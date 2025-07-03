/*
** EPITECH PROJECT, 2025
** testing
** File description:
** init_textbox
*/

#include "utils.h"
#include "struct.h"

void init_textbox_shape(textbox_t *tb)
{
    tb->shape = sfRectangleShape_create();
    sfRectangleShape_setPosition(tb->shape, tb->pos);
    sfRectangleShape_setSize(tb->shape, tb->size);
    sfRectangleShape_setFillColor(tb->shape, (sfColor){60, 60, 60, 255});
    sfRectangleShape_setOutlineThickness(tb->shape, 2);
    sfRectangleShape_setOutlineColor(tb->shape, sfWhite);
}

void init_textbox_text(textbox_t *tb, sfFont *font)
{
    sfFloatRect bounds;

    tb->text = sfText_create();
    if (font)
        sfText_setFont(tb->text, font);
    sfText_setString(tb->text, tb->content);
    sfText_setCharacterSize(tb->text, 18);
    sfText_setFillColor(tb->text, sfWhite);
    bounds = sfText_getLocalBounds(tb->text);
    sfText_setPosition(tb->text, (sfVector2f){
        tb->pos.x + 5,
        tb->pos.y + (tb->size.y - bounds.height) / 2 - 3
    });
}
