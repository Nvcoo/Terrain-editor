/*
** EPITECH PROJECT, 2025
** testing
** File description:
** utils
*/

#include "utils.h"
#include "struct.h"

int is_mouse_over_button(sfVector2i mouse, ui_button_t *button)
{
    return (mouse.x >= button->pos.x &&
        mouse.x <= button->pos.x + button->size.x &&
        mouse.y >= button->pos.y &&
        mouse.y <= button->pos.y + button->size.y);
}
