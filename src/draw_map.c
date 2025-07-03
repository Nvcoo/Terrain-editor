/*
** EPITECH PROJECT, 2025
** testing
** File description:
** draw_map
*/

#include "utils.h"
#include "struct.h"

void draw_single_line(sfRenderWindow *w, sfVector2f pos1, sfVector2f pos2,
    sfColor color)
{
    sfVertex line[2];

    line[0] = (sfVertex){pos1, color, {0, 0}};
    line[1] = (sfVertex){pos2, color, {0, 0}};
    sfRenderWindow_drawPrimitives(w, line, 2, sfLines, NULL);
}

void draw_horizontal_lines(sfRenderWindow *w, game_state_t *s)
{
    int avg_height;
    int is_line_selected;
    sfColor line_color;
    sfVector2f pos1;
    sfVector2f pos2;

    for (int y = 0; y < s->map_h; y++) {
        for (int x = 0; x < s->map_w - 1; x++) {
            avg_height = (s->map[y][x].height + s->map[y][x + 1].height) / 2;
            is_line_selected = s->map[y][x].selected ||
            s->map[y][x + 1].selected;
            line_color = get_altitude_color(avg_height, is_line_selected);
            pos1 = world_to_screen(s->map[y][x].iso_pos, s);
            pos2 = world_to_screen(s->map[y][x + 1].iso_pos, s);
            draw_single_line(w, pos1, pos2, line_color);
        }
    }
}

void draw_vertical_lines(sfRenderWindow *w, game_state_t *s)
{
    int avg_height;
    int is_line_selected;
    sfColor line_color;
    sfVector2f pos1;
    sfVector2f pos2;

    for (int y = 0; y < s->map_h - 1; y++) {
        for (int x = 0; x < s->map_w; x++) {
            avg_height = (s->map[y][x].height + s->map[y + 1][x].height) / 2;
            is_line_selected = s->map[y][x].selected ||
            s->map[y + 1][x].selected;
            line_color = get_altitude_color(avg_height, is_line_selected);
            pos1 = world_to_screen(s->map[y][x].iso_pos, s);
            pos2 = world_to_screen(s->map[y + 1][x].iso_pos, s);
            draw_single_line(w, pos1, pos2, line_color);
        }
    }
}

void draw_lines(sfRenderWindow *w, game_state_t *s)
{
    draw_horizontal_lines(w, s);
    draw_vertical_lines(w, s);
}

void draw_map(sfRenderWindow *w, game_state_t *s)
{
    sfCircleShape *p;
    sfVector2f pos;

    draw_textured_tiles(w, s);
    draw_lines(w, s);
    for (int y = 0; y < s->map_h; y++) {
        for (int x = 0; x < s->map_w; x++) {
            p = sfCircleShape_create();
            sfCircleShape_setRadius(p, 0.5);
            pos = world_to_screen(s->map[y][x].iso_pos, s);
            sfCircleShape_setPosition(p, (sfVector2f){pos.x - 2, pos.y - 2});
            sfCircleShape_setFillColor(p,
            s->map[y][x].selected ? sfRed : s->map[y][x].color);
            sfRenderWindow_drawCircleShape(w, p, NULL);
            sfCircleShape_destroy(p);
        }
    }
}
