/*
** EPITECH PROJECT, 2025
** testing
** File description:
** handle_event
*/

#include "utils.h"
#include "struct.h"

void events(game_state_t *s, sfEvent *e)
{
    if (e->type == sfEvtClosed)
        sfRenderWindow_close(s->mn.window);
    if (e->type == sfEvtResized)
        res_view(s);
}

void handle_events(game_state_t *s)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(s->mn.window, &e)) {
        events(s, &e);
        handle_text(s, &e);
        handle_keyboard(s, &e);
        handle_mouse_buttons(s, &e);
        handle_mouse_wheel(s, &e);
    }
}
