/*
** EPITECH PROJECT, 2025
** testing
** File description:
** create_background
*/

#include "utils.h"
#include "struct.h"

background_t create_background(sfRenderWindow *window)
{
    background_t bg;
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2u texture_size;
    sfVector2f scale;

    bg.sprite = sfSprite_create();
    bg.texture = sfTexture_createFromFile("assets/menu.png", NULL);
    texture_size = sfTexture_getSize(bg.texture);
    scale.x = (float)window_size.x / texture_size.x;
    scale.y = (float)window_size.y / texture_size.y;
    sfSprite_setTexture(bg.sprite, bg.texture, sfTrue);
    sfSprite_setScale(bg.sprite, scale);
    return bg;
}
