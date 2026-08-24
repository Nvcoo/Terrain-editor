/*
** EPITECH PROJECT, 2025
** testing
** File description:
** draw_textured_tiles
*/

#include "utils.h"
#include "struct.h"

void calculate_tile_corners(game_state_t *s, int x, int y,
    sfVector2f *corner_points)
{
    sfVector2f top_left = world_to_screen(s->map[y][x].iso_pos, s);
    sfVector2f top_right = (x + 1 < s->map_w) ?
        world_to_screen(s->map[y][x + 1].iso_pos, s) : top_left;
    sfVector2f bottom_left = (y + 1 < s->map_h) ?
        world_to_screen(s->map[y + 1][x].iso_pos, s) : top_left;
    sfVector2f bottom_right = (x + 1 < s->map_w && y + 1 < s->map_h) ?
        world_to_screen(s->map[y + 1][x + 1].iso_pos, s) : top_left;

    corner_points[0] = top_left;
    corner_points[1] = top_right;
    corner_points[2] = bottom_right;
    corner_points[3] = bottom_left;
}

void draw_single_textured_tile(sfRenderWindow *w, game_state_t *s, int x,
    int y)
{
    sfVertex corner[4];
    sfVector2f corner_pt[4];
    sfVector2u tex_size;
    sfColor tile_color;
    sfRenderStates states;

    calculate_tile_corners(s, x, y, corner_pt);
    tex_size = sfTexture_getSize(s->grass_texture);
    corner[0] = (sfVertex){corner_pt[0], sfWhite, {0, 0}};
    corner[1] = (sfVertex){corner_pt[1], sfWhite, {tex_size.x, 0}};
    corner[2] = (sfVertex){corner_pt[2], sfWhite, {tex_size.x, tex_size.y}};
    corner[3] = (sfVertex){corner_pt[3], sfWhite, {0, tex_size.y}};
    tile_color = get_altitude_color(s->map[y][x].height,
        s->map[y][x].selected);
    for (int i = 0; i < 4; i++)
        corner[i].color = tile_color;
    states = sfRenderStates_default();
    states.texture = s->grass_texture;
    sfRenderWindow_drawPrimitives(w, corner, 4, sfQuads, &states);
}

void draw_textured_tiles(sfRenderWindow *w, game_state_t *s)
{
    if (!s->grass_texture)
        return;
    for (int y = 0; y < s->map_h - 1; y++) {
        for (int x = 0; x < s->map_w - 1; x++) {
            draw_single_textured_tile(w, s, x, y);
        }
    }
}
