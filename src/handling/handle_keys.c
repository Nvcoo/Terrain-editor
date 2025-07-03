/*
** EPITECH PROJECT, 2025
** testing
** File description:
** handle_keys
*/

#include "utils.h"
#include "struct.h"

static void handle_movement(game_state_t *s, sfKeyCode key)
{
    if (key == sfKeyLeft)
        s->camera_offset.x += 20;
    if (key == sfKeyRight)
        s->camera_offset.x -= 20;
    if (key == sfKeyUp)
        s->camera_offset.y += 20;
    if (key == sfKeyDown)
        s->camera_offset.y -= 20;
}

static void handle_zoom(game_state_t *s, sfKeyCode key)
{
    if (key == sfKeyAdd)
        s->mn.zoom *= 1.1f;
    if (key == sfKeySubtract) {
        s->mn.zoom /= 1.1f;
        if (s->mn.zoom < 0.1f)
            s->mn.zoom = 0.1f;
    }
}

void handle_text(game_state_t *s, sfEvent *e)
{
    if (e->type == sfEvtTextEntered)
        handle_text_input(s, e->text.unicode);
}

void handle_keyboard(game_state_t *s, sfEvent *e)
{
    if (e->type == sfEvtKeyPressed) {
        if (e->key.code == sfKeyEscape)
            sfRenderWindow_close(s->mn.window);
        handle_movement(s, e->key.code);
        handle_zoom(s, e->key.code);
        handle_tools(s, e->key.code);
        handle_brush(s, e->key.code);
    }
}
