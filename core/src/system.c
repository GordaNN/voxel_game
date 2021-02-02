/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* This module contains system functions.
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "core/system.h"

/* This function initializes the glfw library */
bool system_initialize(void)
{
	if (glfwInit() != GLFW_TRUE)
		return false;
	return true;
}

/* This function load glad */
bool system_opengl_load(void)
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return false;
	return true;
}

/* This function terminates the glfw library and event's queue */
void system_finalize(void)
{
	glfwTerminate();
}

/* This function returns the value of the GLFW timer */
double system_get_time(void)
{
	return glfwGetTime();
}
