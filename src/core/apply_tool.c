/*
** EPITECH PROJECT, 2025
** testing
** File description:
** apply_tool
*/

#include "utils.h"
#include "struct.h"

void select_tool(tile_t *t, game_state_t *s)
{
    if (s->current_tool == TOOL_RAISE && t->height < MAX_HEIGHT)
        t->height++;
    if (s->current_tool == TOOL_LOWER && t->height > - MAX_HEIGHT)
        t->height--;
    if (s->current_tool == TOOL_FLATTEN || s->current_tool == TOOL_RESET)
        t->height = 0;
}

void implement_tool(game_state_t *s, int x, int y)
{
    tile_t *t;

    if (x < 0 || x >= s->map_w || y < 0 || y >= s->map_h)
        return;
    t = &s->map[y][x];
    select_tool(t, s);
    t->iso_pos = project_iso_point(x * TILE_SPACING, y * TILE_SPACING,
        t->height * 8);
    if (t->height > 0)
        t->color = (sfColor){150 + t->height * 10, 100 + t->height * 5, 50,
        255};
    else if (t->height < 0)
        t->color = (sfColor){50, 100 - t->height * 5, 150 - t->height * 10,
        255};
    else
        t->color = sfGreen;
}

void apply_tool(game_state_t *s, int tx, int ty)
{
    int by;
    int bx;
    int x;
    int y;

    if (tx < 0 || tx >= s->map_w || ty < 0 || ty >= s->map_h)
        return;
    for (by = -s->ext.brush_size; by <= s->ext.brush_size; by++) {
        for (bx = -s->ext.brush_size; bx <= s->ext.brush_size; bx++) {
            x = tx + bx;
            y = ty + by;
            implement_tool(s, x, y);
        }
    }
}
