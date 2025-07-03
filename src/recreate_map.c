/*
** EPITECH PROJECT, 2025
** testing
** File description:
** recreate_map
*/

#include "utils.h"
#include "struct.h"

void recreate_map(game_state_t *s, int new_width, int new_height)
{
    for (int y = 0; y < s->map_h; y++)
        free(s->map[y]);
    free(s->map);
    s->map_w = new_width;
    s->map_h = new_height;
    s->map = malloc(s->map_h * sizeof(tile_t *));
    for (int y = 0; y < s->map_h; y++) {
        s->map[y] = malloc(s->map_w * sizeof(tile_t));
        for (int x = 0; x < s->map_w; x++)
            s->map[y][x] = (tile_t){0, sfGreen,
            project_iso_point(x * TILE_SPACING, y * TILE_SPACING, 0), 0};
    }
    s->ext.selected_x = -1;
    s->ext.selected_y = -1;
}
