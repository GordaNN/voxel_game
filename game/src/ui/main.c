/*
* Author: Naumenko Nikolay
* Email: v-v-vlasov1999@mail.ru
*
* Module description:
* Here located the entry point and main loop of application.
*/

#include "application/application.h"
#include "application/application_events.h"
#include "application/binder.h"

/* This function is entry point of application */
int main(void)
{
    /* Create application */
    application_t app;
    if (!application_create(&app))
        return -1;

    /* Last cursore screen position */
    vec2d_t last_cursore = vec2d_create(0.0, 0.0);

    /* Main game loop */
    while (!window_is_closed(app.window))
    {
        /* Collecting window events */
        window_poll_events();

        /* Processing window events */
        window_event_t window_event;
        if (window_get_event(&window_event))
        {
            application_event_t app_event = VOID;
            if (window_event.action == CORE_KEY_PRESS)
                app_event = binder_get_keydown_event(window_event.key);
            else if (window_event.action == CORE_KEY_RELEASE)
                app_event = binder_get_keyup_event(window_event.key);
            application_handle_event(&app, app_event);
        }

        /* Processing window event of the cursor separately for smoother camera rotation */
        if (window_get_cursor_event(&window_event))
        {
            vec2d_t cursore = vec2d_create(window_event.x, window_event.y);
            if (!binder_is_showed_cursor())
                application_rotate_camera(&app, vec2d_f(vec2d_sub(last_cursore, cursore)));
            last_cursore = cursore;
        }

        application_calculate_physics(&app);
        application_draw_world(&app);

        /* Changing window buffer */
        window_swap_buffers(app.window);
    }

    /* Destroy application */
    application_destroy(&app);

    return 0;
}
