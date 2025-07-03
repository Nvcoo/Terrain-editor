/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** destroy_background
*/

#include "utils.h"
#include "struct.h"

void destroy_background(background_t bg)
{
    sfSprite_destroy(bg.sprite);
    sfTexture_destroy(bg.texture);
}
