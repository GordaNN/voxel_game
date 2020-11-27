/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* Here located the entry point and main loop of application
*/

#include <math.h>
#include "graphics/camera.h"
#include "graphics/graphical_context.h"
#include "graphics/window.h"
#include "world/world.h"

/* 
* This function calculates position of camera
* camera_p - pointer to camera
* speed - vector of camera speed
* delta_time - time from last calculation
*/
void calculate_camera_position(
        camera_t* camera_p,
        vec3f_t   speed,
        float     delta_time);

/* 
* This function process events of window
* event - window event
* time - system time
* camera_p - pointer to camera
* speed_p - pointer of camera speed
*/
void handle_window_event(
        window_event_t event,
        double         time,
        camera_t*      camera_p,
        vec3f_t*       speed_p);

/* This function is entry point of application */
int main(void)
{
    /* Initializing the system (glfw) */
    if (!system_initialize())
        return -1;

    /* Creating window */
    window_t window;
    if (!window_create(&window, "Game", 800, 600))
    {
        system_finalize();
        return -1;
    }

    /* Creating and configuring the openGL context */
    graphical_context_t context;
    if (!graphical_context_create(&context, (GLADloadproc)system_load_proc_function()))
    {
        system_finalize();
        return -1;
    }
    graphical_context_set_viewport(0, 0, 800, 600);

    /* Creating and configuring a camera */
    camera_t camera =
    {
        .projection         = mat4f_set(0.0f),
        .position           = vec3d_create(0.0, 8.0, 0.0),
        .rotation           = vec3f_create(0.0f, 0.0f, 0.0f),
        .fov                = 1.309f,
        .screen_proportions = 4.0f / 3.0f,
        .view_distance      = 1000.0f
    };
    camera_calculate_projection(&camera);

    /* Linking the camera to graphical context */
    context.camera_p = &camera;

    /* Camera speed vector and last position calculation time */
    vec3f_t camera_speed = vec3f_create(0.0f, 0.0f, 0.0f);
    double last_calculation_position_time = system_get_time();

    /* Creating and generating world */
    world_t world;
    world_create(&world, 0);
    if (world_generate(&world) == false)
    {
        system_finalize();
        return -1;
    }

    /* Main game loop */
    while (!window_is_closed(window))
    {
        /* Collecting window events */
        window_poll_events();

        /* Processing window events */
        window_event_t event;
        if (window_get_event(&event))
        {
            if (event.key == GLFW_KEY_ESCAPE)
                window_close(window);
            else
                handle_window_event(event, system_get_time(), &camera, &camera_speed);
        }

        /* Processing window event of the cursor separately for smoother camera rotation */
        if (window_get_cursor_event(&event))
            handle_window_event(event, system_get_time(), &camera, &camera_speed);
        
        /* Calculating the camera position */
        calculate_camera_position(
                &camera,
                camera_speed,
                system_get_time() - last_calculation_position_time);
        last_calculation_position_time = system_get_time();

        /* Start drawing */
        graphical_context_begin_drawing();
        graphical_context_begin_drawing_voxels(&context);

        /* 
        * Processing the world
        * draw chunks, allocate or release video memory (depends on the state of the chunk)
        */
        world_draw(&world, &context);

        /* Changing window buffer */
        window_swap_buffers(window);
    }

    /* Releasing resources */
    world_destroy(&world);
    graphical_context_destroy(&context);
    system_finalize();

    return 0;
}

/*
* This function calculates position of camera
* camera_p - pointer to camera
* speed - vector of camera speed
* delta_time - time from last calculation
*/
void calculate_camera_position(
        camera_t* camera_p,
        vec3f_t   speed,
        float     delta_time)
{
    const vec3f_t delta_position = vec3f_mul_n(speed, delta_time);

    camera_p->position.x += cosf(camera_p->rotation.yaw) * delta_position.x -
                            sinf(camera_p->rotation.yaw) * delta_position.z;

    camera_p->position.y += delta_position.y;

    camera_p->position.z += cosf(camera_p->rotation.yaw) * delta_position.z +
                            sinf(camera_p->rotation.yaw) * delta_position.x;
}

/*
* This function process events of window
* event - window event
* time - system time
* camera_p - pointer to camera
* speed_p - pointer of camera speed
*/
void handle_window_event(
        window_event_t event,
        double         time,
        camera_t*      camera_p,
        vec3f_t*       speed_p)
{
    /*
    * Current state of events
    *
    * Yes, I know that static variables contradict the functional style of programming,
    * but for now it will be so.
    * Soon I will create "input" module in the next patch.
    */
    static double last_cursore_x = 400.0;
    static double last_cursore_y = 300.0;
    static bool is_forward = false;
    static bool is_back    = false;
    static bool is_left    = false;
    static bool is_right   = false;
    static bool is_up      = false;
    static bool is_down    = false;

    /* Handle window events */
    switch (event.type)
    {
    case WINDOW_KEY_EVENT:
        switch (event.key)
        {
        case GLFW_KEY_W:
            if (!is_back)
                if (event.action == GLFW_PRESS)
                {
                    static double last_activation_time = 0.0;
                    speed_p->z = (time - last_activation_time < 0.3) ? 10.0f : 3.0f;
                    last_activation_time = time;
                    is_forward = true;
                }
                else
                {
                    speed_p->z = 0.0f;
                    is_forward = false;
                }
            break;
        case GLFW_KEY_S:
            if (!is_forward)
                if (event.action == GLFW_PRESS)
                {
                    static double last_activation_time = 0.0;
                    speed_p->z = (time - last_activation_time < 0.3) ? -10.0f : -3.0f;
                    last_activation_time = time;
                    is_back = true;
                }
                else
                {
                    speed_p->z = 0.0f;
                    is_back = false;
                }
            break;
        case GLFW_KEY_A:
            if (!is_right)
                if (event.action == GLFW_PRESS)
                {
                    static double last_activation_time = 0.0;
                    speed_p->x = (time - last_activation_time < 0.3) ? 10.0f : 3.0f;
                    last_activation_time = time;
                    is_left = true;
                }
                else
                {
                    speed_p->x = 0.0f;
                    is_left = false;
                }
            break;
        case GLFW_KEY_D:
            if (!is_left)
                if (event.action == GLFW_PRESS)
                {
                    static double last_activation_time = 0.0;
                    speed_p->x = (time - last_activation_time < 0.3) ? -10.0f : -3.0f;
                    last_activation_time = time;
                    is_right = true;
                }
                else
                {
                    speed_p->x = 0.0f;
                    is_right = false;
                }
            break;
        case GLFW_KEY_LEFT_SHIFT:
            if (!is_down)
                if (event.action == GLFW_PRESS)
                {
                    static double last_activation_time = 0.0;
                    speed_p->y = (time - last_activation_time < 0.3) ? 10.0f : 4.0f;
                    last_activation_time = time;
                    is_up = true;
                }
                else
                {
                    speed_p->y = 0.0f;
                    is_up = false;
                }
            break;
        case GLFW_KEY_LEFT_CONTROL:
            if (!is_up)
                if (event.action == GLFW_PRESS)
                {
                    static double last_activation_time = 0.0;
                    speed_p->y = (time - last_activation_time < 0.3) ? -10.0f : -4.0f;
                    last_activation_time = time;
                    is_down = true;
                }
                else
                {
                    speed_p->y = 0.0f;
                    is_down = false;
                }
            break;
        }
        break;
    case WINDOW_CURSOR_POS_EVENT:
    {
        const float sensitivity = 0.013f;
        const float two_pi  = 6.283185307f;
        const float half_pi = 1.570796327f;

        camera_p->rotation.yaw   += sensitivity * (float)(event.x - last_cursore_x);
        camera_p->rotation.pitch += sensitivity * (float)(last_cursore_y - event.y);

        if (camera_p->rotation.yaw <= 0.0f)
            camera_p->rotation.yaw += two_pi;
        else if (camera_p->rotation.yaw >= two_pi)
            camera_p->rotation.yaw -= two_pi;

        if (camera_p->rotation.pitch < -half_pi + 0.001f)
            camera_p->rotation.pitch = -half_pi + 0.001f;
        else if (camera_p->rotation.pitch > half_pi - 0.001f)
            camera_p->rotation.pitch = half_pi - 0.001f;

        last_cursore_x = event.x;
        last_cursore_y = event.y;
        break;
    }
    }
}
