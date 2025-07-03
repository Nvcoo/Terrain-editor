/*
** EPITECH PROJECT, 2025
** testing
** File description:
** project_iso_point
*/

#include "utils.h"

sfVector2f project_iso_point(int x, int y, int z)
{
    return (sfVector2f){cos(ANGLE_X) * x - cos(ANGLE_X) * y,
        sin(ANGLE_Y) * y + sin(ANGLE_Y) * x - z};
}
