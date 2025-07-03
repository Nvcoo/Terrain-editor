/*
** EPITECH PROJECT, 2025
** testing
** File description:
** handle_effects
*/

#include "utils.h"
#include "struct.h"

void handle_brush(game_state_t *s, sfKeyCode key)
{
    if (key == sfKeyQ) {
        if (s->ext.brush_size > 0)
            s->ext.brush_size--;
    }
    if (key == sfKeyE) {
        if (s->ext.brush_size < 5)
            s->ext.brush_size++;
    }
}

void handle_tools(game_state_t *s, sfKeyCode key)
{
    if (key == sfKeyNum1)
        s->current_tool = TOOL_RAISE;
    if (key == sfKeyNum2)
        s->current_tool = TOOL_LOWER;
    if (key == sfKeyNum3)
        s->current_tool = TOOL_FLATTEN;
    if (key == sfKeyNum4)
        s->current_tool = TOOL_RESET;
}
