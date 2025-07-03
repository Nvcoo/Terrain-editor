/*
** EPITECH PROJECT, 2025
** testing
** File description:
** update_background
*/

#include "utils.h"
#include "struct.h"

void update_background(background_t *bg, sfRenderWindow *window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2u texture_size = sfTexture_getSize(bg->texture);
    sfVector2f scale;

    scale.x = (float)window_size.x / texture_size.x;
    scale.y = (float)window_size.y / texture_size.y;
    sfSprite_setScale(bg->sprite, scale);
}
