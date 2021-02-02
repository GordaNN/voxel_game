/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains struct of octree and functions for working with them.
*/

#include <memory.h>
#include "core/utils/containers/octree.h"

/*
* This function recursively creates nodes of octree
* Octree is stored in the form of a pointer
* It returns true if all is OK and
* false if can't allocate memory
* tree_pp - pointer to node poointer
* level - level (height) of the tree
*/
bool octree_create_recursive(
        octree_t**   tree_pp,
        unsigned int level);

/*
* This function recursively fills the tree with elements from volume array
* Used only from 'octree_fill' function
* tree_p - node poointer
* data_volume_array_p - volume array of data (xyz)
* x - index of array by x. Equal to 0 when called
* y - index of array by y. Equal to 0 when called
* z - index of array by z. Equal to 0 when called
* d - index increase. Equal to length of volume array in one direction when called
* n - length of volume array in one direction
* s - size of one element of volume array
* f - selection function
*/
void octree_fill_recursive(
        octree_t*   tree_p,
        const void* data_volume_array_p,
        size_t      x,
        size_t      y,
        size_t      z,
        size_t      d,
        size_t      n,
        size_t      s,
        bool(*f)(void*));

/*
* This recursive function returns copy not empty leaves values to array
* tree_p - node poointer
* array_p - array pointer
* size - size of one element
* i - pointer to current index to array
*/
bool octree_drawing_array_recursive(
        const octree_t* tree_p,
        void*           array_p,
        size_t          size,
        size_t*         i);

/*
* This function creates node of octree
* Octree is stored in the form of a pointer
* It returns true if all is OK and
* false if can't allocate memory
* tree_pp - pointer to node poointer
*/
bool octree_create(
        octree_t** tree_pp)
{
    *tree_pp = malloc(sizeof(octree_t));
    memset(*tree_pp, 0, sizeof(octree_t));
    if (*tree_pp == NULL)
        return false;
    return true;
}

/*
* This function destroys the tree and all subtrees along with the data
* Octree is stored in the form of a pointer
* tree_pp - pointer to node poointer
*/
void octree_destroy(
        octree_t** tree_pp)
{
    if (*tree_pp != NULL)
    {
        for (size_t i = 0; i < 8; ++i)
            if ((*tree_pp)->subtrees_p[i] != NULL)
                octree_destroy((*tree_pp)->subtrees_p[i]);

        if ((*tree_pp)->data_p != NULL)
            free((*tree_pp)->data_p);

        free(*tree_pp);
        *tree_pp = NULL;
    }
}

/*
* This function fills the tree with elements from volume array
* tree_pp - poiter to node poointer
* data_volume_array_p - volume array of data (xyz)
* number - length of volume array in one direction (only 1, 2, 4, 8, 16, etc...)
* size - size of one element of volume array
* f - selection function
* View of data_volume_array_p in space for number = 2:
* array = 0 1 2 3 4 5 6 7
*      3-----------7
*     /|          /|
*    /           / |
*   /  |        /  |
*  2-----------6   |
*  |   1--  -- | --5
*  |  /        |  /
*  |           | /
*  |/          |/
*  0-----------4
*/
bool octree_fill(
        octree_t**  tree_pp,
        const void* data_volume_array_p,
        size_t      number,
        size_t      size,
        bool(*selection)(void*))
{
    /* Destroy old tree */
    octree_destroy(tree_pp);

    /* Calculate max level of tree */
    unsigned int max_level = 1;
    for (size_t i = 1; i != number; i <<= 1)
        ++max_level;

    /* Creation of tree */
    if (octree_create_recursive(tree_pp, max_level) == false)
        return false;

    /* Fill tree */
    octree_fill_recursive(*tree_pp, data_volume_array_p, 0, 0, 0, number, number, size, selection);

    return true;
}

/* 
* This function returns number of octree's not empty leaves
* tree_p - node poointer
*/
size_t octree_drawing_array_number(
        const octree_t* tree_p)
{
    size_t number = 0;
    for (size_t i = 0; i < 8; ++i)
        if (tree_p->subtrees_p[i] != NULL)
            number += octree_drawing_array_number(tree_p->subtrees_p[i]);

    if (number == 0 && tree_p->data_p != NULL)
        return 1;
    return number;
}

/*
* This function returns copy not empty leaves values to array
* tree_p - node poointer
* array_p - array pointer
* size - size of one element
*/
void octree_drawing_array(
        const octree_t* tree_p,
        void*           array_p,
        size_t          size)
{
    size_t i = 0;
    octree_drawing_array_recursive(tree_p, array_p, size, &i);
}

/*
* This function recursively creates nodes of octree
* Octree is stored in the form of a pointer
* It returns true if all is OK and
* false if can't allocate memory
* tree_pp - pointer to node poointer
* level - level (height) of the tree
*/
bool octree_create_recursive(
        octree_t**   tree_pp,
        unsigned int level)
{
    if (octree_create(tree_pp) == false)
        return false;

    if (--level > 0)
        for (size_t i = 0; i < 8; ++i)
            if (octree_create_recursive(&(*tree_pp)->subtrees_p[i], level) == false)
                return false;

    return true;
}

/*
* This function recursively fills the tree with elements from volume array
* Used only from 'octree_fill' function
* tree_p - node poointer
* data_volume_array_p - volume array of data (xyz)
* x - index of array by x. Equal to 0 when called
* y - index of array by y. Equal to 0 when called
* z - index of array by z. Equal to 0 when called
* d - index increase. Equal to length of volume array in one direction when called
* n - length of volume array in one direction
* s - size of one element of volume array
* f - selection function
*/
void octree_fill_recursive(
        octree_t*   tree_p,
        const void* data_volume_array_p,
        size_t      x,
        size_t      y,
        size_t      z,
        size_t      d,
        size_t      n,
        size_t      s,
        bool(*f)(void*))
{
    /* Reduce the increase by 2 times */
    d = d >> 1;

    if (d == 0)
    {
        /* We have reached the end, copy the element */
        void* pointer = (char*)data_volume_array_p + s * (n * n * x + n * y + z);
        if (f == NULL || f(pointer) == true)
        {
            tree_p->data_p = malloc(s);
            memcpy(tree_p->data_p, pointer, s);
        }
    } 
    else
    {
        /* Going down recursively increasing x y z indexes by d */
        octree_fill_recursive(tree_p->bfr, data_volume_array_p, x + d, y,     z + d, d, n, s, f);
        octree_fill_recursive(tree_p->bnr, data_volume_array_p, x + d, y,     z,     d, n, s, f);
        octree_fill_recursive(tree_p->bnl, data_volume_array_p, x,     y,     z,     d, n, s, f);
        octree_fill_recursive(tree_p->bfl, data_volume_array_p, x,     y,     z + d, d, n, s, f);
        octree_fill_recursive(tree_p->tfr, data_volume_array_p, x + d, y + d, z + d, d, n, s, f);
        octree_fill_recursive(tree_p->tnr, data_volume_array_p, x + d, y + d, z,     d, n, s, f);
        octree_fill_recursive(tree_p->tnl, data_volume_array_p, x,     y + d, z,     d, n, s, f);
        octree_fill_recursive(tree_p->tfl, data_volume_array_p, x,     y + d, z + d, d, n, s, f);
    }
}

/*
* This recursive function returns copy not empty leaves values to array
* tree_p - node poointer
* array_p - array pointer
* size - size of one element
* i - pointer to current index to array
*/
bool octree_drawing_array_recursive(
        const octree_t* tree_p,
        void*           array_p,
        size_t          size,
        size_t*         i)
{
    bool last = true;
    for (size_t j = 0; j < 8; ++j)
        if (tree_p->subtrees_p[j] != NULL)
            /* This order is required so that the function is called regardless of 'last' value */
            last = octree_drawing_array_recursive(tree_p->subtrees_p[j], array_p, size, i) && last;

    if (last == true && tree_p->data_p != NULL)
    {
        memcpy((char*)array_p + *i, tree_p->data_p, size);
        *i += size;
        return false;
    }
    return last;
}
