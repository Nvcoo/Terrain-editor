/*
** EPITECH PROJECT, 2025
** testing
** File description:
** handle_mouse
*/

#include "utils.h"
#include "struct.h"

static void handle_click(game_state_t *s, sfVector2i tile)
{
    if (tile.x >= 0 && tile.y >= 0) {
        apply_tool(s, tile.x, tile.y);
        s->ext.selected_x = tile.x;
        s->ext.selected_y = tile.y;
    }
}

void handle_mouse_buttons(game_state_t *s, sfEvent *e)
{
    sfVector2i tile;

    if (e->type == sfEvtMouseButtonPressed) {
        if (e->mouseButton.button == sfMouseLeft &&
            e->mouseButton.x > UI_WIDTH) {
            tile = screen_to_tile((sfVector2i){e->mouseButton.x,
                e->mouseButton.y}, s);
            handle_click(s, tile);
        }
    }
}

void handle_mouse_wheel(game_state_t *s, sfEvent *e)
{
    if (e->type == sfEvtMouseWheelScrolled) {
        s->mn.zoom *= (e->mouseWheelScroll.delta > 0) ? 1.1f : (1.0f / 1.1f);
        if (s->mn.zoom < 0.1f)
            s->mn.zoom = 0.1f;
    }
}
