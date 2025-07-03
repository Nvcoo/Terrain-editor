/*
** EPITECH PROJECT, 2025
** testing
** File description:
** save_map
*/

#include "utils.h"
#include "struct.h"
#include <stdio.h>

int save_map(game_state_t *s, const char *filename)
{
    FILE *file = fopen(filename, "w");

    if (!file) {
        printf("Could not save map\n");
        return 0;
    }
    fprintf(file, "%d %d\n", s->map_w, s->map_h);
    for (int y = 0; y < s->map_h; y++) {
        for (int x = 0; x < s->map_w; x++)
            fprintf(file, "%d %d %d\n", x, y, s->map[y][x].height);
    }
    fclose(file);
    return 0;
}
