/*
** EPITECH PROJECT, 2025
** testing
** File description:
** button_colors
*/

#include "utils.h"
#include "struct.h"

sfColor get_button_color(button_state_t state, int is_current_tool)
{
    sfColor color = {100, 100, 100, 255};

    if (state == BTN_HOVER)
        color = (sfColor){150, 150, 150, 255};
    else if (state == BTN_CLICKED)
        color = (sfColor){200, 200, 200, 255};
    if (is_current_tool)
        color = (sfColor){180, 180, 100, 255};
    return color;
}

sfColor get_brush_button_color(button_state_t state)
{
    sfColor color = {80, 80, 80, 255};

    if (state == BTN_HOVER)
        color = (sfColor){120, 120, 120, 255};
    else if (state == BTN_CLICKED)
        color = (sfColor){160, 160, 160, 255};
    return color;
}

sfColor get_apply_button_color(button_state_t state)
{
    sfColor color = {100, 150, 100, 255};

    if (state == BTN_HOVER)
        color = (sfColor){120, 180, 120, 255};
    else if (state == BTN_CLICKED)
        color = (sfColor){140, 200, 140, 255};
    return color;
}
