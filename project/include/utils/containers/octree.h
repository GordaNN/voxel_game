/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains struct of octree and functions for working with them.
*/

#ifndef UTILS_CONTAINERS_OCTREE_H
#define UTILS_CONTAINERS_OCTREE_H

#include <stdlib.h>
#include <stdbool.h>

/*
* Structure of sparse octree
* data_p - data void pointer
* bfr bnr bnl bfl tfr tnr tnl tfl - subtrees pointers
* subtrees_p - array of subtrees pointers
* Designation:
* b - bottom
* t - top
* f - far
* n - near
* l - left
* r - top
* View:
*     tfl---------tfr
*     /|          /|
*    /           / |
*   /  |        /  |
* tnl---------tnr  |
*  |  bfl-  -- | -bfr
*  |  /        |  /
*  |           | /
*  |/          |/
* bnl---------bnr
*/
typedef struct octree_t
{
    union
    {
        struct
        {
            struct octree_t* bfr;
            struct octree_t* bnr;
            struct octree_t* bnl;
            struct octree_t* bfl;
            struct octree_t* tfr;
            struct octree_t* tnr;
            struct octree_t* tnl;
            struct octree_t* tfl;
        };
        struct octree_t* subtrees_p[8];
    };
    void* data_p;
} octree_t;

/*
* This function creates node of octree
* Octree is stored in the form of a pointer
* It returns true if all is OK and
* false if can't allocate memory
* tree_pp - pointer to node poointer
*/
bool octree_create(
        octree_t** tree_pp);

/*
* This function destroys the tree and all subtrees along with the data
* Octree is stored in the form of a pointer
* tree_pp - pointer to node poointer
*/
void octree_destroy(
        octree_t** tree_pp);

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
        bool(*selection)(void*));

/* 
* This function returns number of octree's not empty leaves
* tree_p - node poointer
*/
size_t octree_drawing_array_number(
        const octree_t* tree_p);

/*
* This function returns copy not empty leaves values to array
* tree_p - node poointer
* array_p - array pointer
* size - size of one element
*/
void octree_drawing_array(
        const octree_t* tree_p,
        void*           array_p,
        size_t          size);

#endif // UTILS_CONTAINERS_OCTREE_H
