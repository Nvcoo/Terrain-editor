/*
** EPITECH PROJECT, 2025
** testing
** File description:
** res_view
*/

#include "utils.h"
#include "struct.h"

void res_view(game_state_t *s)
{
    sfView *view;
    sfFloatRect view_area;

    s->mn.window_size = sfRenderWindow_getSize(s->mn.window);
    view = sfView_create();
    view_area = (sfFloatRect){0, 0, s->mn.window_size.x, s->mn.window_size.y};
    sfView_reset(view, view_area);
    sfRenderWindow_setView(s->mn.window, view);
    sfView_destroy(view);
    s->camera_offset = (sfVector2f){
        (float)s->mn.window_size.x / 2 - (float)UI_WIDTH / 2,
        (float)s->mn.window_size.y / 2
    };
    if (s->txt.help_text)
        sfText_setPosition(s->txt.help_text,
        (sfVector2f){UI_WIDTH + 10, s->mn.window_size.y - 40});
}
