/*
** EPITECH PROJECT, 2025
** testing
** File description:
** world_to_screen
*/

#include "utils.h"
#include "struct.h"

sfVector2f world_to_screen(sfVector2f world, game_state_t *s)
{
    return (sfVector2f){world.x * s->mn.zoom + s->camera_offset.x,
        world.y * s->mn.zoom + s->camera_offset.y};
}
