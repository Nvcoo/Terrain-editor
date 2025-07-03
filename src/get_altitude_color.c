/*
** EPITECH PROJECT, 2025
** testing
** File description:
** get_altitude_color
*/

#include "utils.h"

sfColor get_altitude_color(int height, int is_selected)
{
    int brown_intensity;
    int blue_intensity;

    if (is_selected)
        return sfRed;
    if (height == 0)
        return (sfColor){50, 200, 50, 255};
    if (height > 0) {
        brown_intensity = 139 + (height * 80 / MAX_HEIGHT);
        if (brown_intensity > 255)
            brown_intensity = 255;
        return (sfColor){brown_intensity, brown_intensity * 0.7f,
            brown_intensity * 0.4f, 255};
    } else {
        blue_intensity = 100 + ((-height) * 100 / MAX_HEIGHT);
        if (blue_intensity > 255)
            blue_intensity = 255;
        return (sfColor){30, 80, blue_intensity, 255};
    }
}
