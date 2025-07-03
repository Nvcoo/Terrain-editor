/*
** EPITECH PROJECT, 2025
** testing
** File description:
** screen_to_tile
*/

#include "utils.h"
#include "struct.h"

void find_closest_tile(int y, float wx, float wy, tile_info_t *tile)
{
    sfVector2f pos;
    float dx;
    float dy;
    float dist;

    for (int x = 0; x < tile->s->map_w; x++) {
        pos = tile->s->map[y][x].iso_pos;
        dx = wx - pos.x;
        dy = wy - pos.y;
        dist = sqrt(dx * dx + dy * dy);
        if (dist < tile->min_dist && dist < (float)TILE_SPACING / 2) {
            tile->min_dist = dist;
            tile->tile = (sfVector2i){x, y};
        }
    }
}

sfVector2i screen_to_tile(sfVector2i screen, game_state_t *s)
{
    float wx;
    float wy;
    tile_info_t tile;

    wx = (screen.x - s->camera_offset.x) / s->mn.zoom;
    wy = (screen.y - s->camera_offset.y) / s->mn.zoom;
    tile.s = s;
    tile.min_dist = 1000000.0f;
    tile.tile = (sfVector2i){-1, -1};
    for (int y = 0; y < s->map_h; y++)
        find_closest_tile(y, wx, wy, &tile);
    return tile.tile;
}
