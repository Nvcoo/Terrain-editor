/*
** EPITECH PROJECT, 2025
** testing
** File description:
** update_textboxes
*/

#include "utils.h"
#include "struct.h"

void activate_textbox(game_state_t *s, textbox_t *tb, int mouse_clicked)
{
    if (mouse_clicked && !s->ext.mouse_button_pressed) {
        for (int j = 0; j < s->txt.textbox_count; j++)
            s->textboxes[j].is_active = 0;
        tb->is_active = 1;
        tb->cursor_pos = strlen(tb->content);
    }
}

void handle_interaction(game_state_t *s, textbox_t *tb, sfVector2i mouse,
    int mouse_clicked)
{
    if (mouse.x >= tb->pos.x && mouse.x <= tb->pos.x + tb->size.x &&
        mouse.y >= tb->pos.y && mouse.y <= tb->pos.y + tb->size.y) {
        activate_textbox(s, tb, mouse_clicked);
    } else if (mouse_clicked && !s->ext.mouse_button_pressed)
        tb->is_active = 0;
}

void set_textbox_colors(textbox_t *tb)
{
    sfColor color;

    if (tb->is_active) {
        color = (sfColor){80, 80, 120, 255};
        sfRectangleShape_setOutlineColor(tb->shape,
            (sfColor){100, 100, 255, 255});
    } else {
        color = (sfColor){60, 60, 60, 255};
        sfRectangleShape_setOutlineColor(tb->shape, sfWhite);
    }
    sfRectangleShape_setFillColor(tb->shape, color);
}

void update_textboxes(game_state_t *s)
{
    sfVector2i mouse;
    int mouse_clicked;
    int i;
    textbox_t *tb;
    sfFloatRect bounds;

    mouse = sfMouse_getPositionRenderWindow(s->mn.window);
    mouse_clicked = sfMouse_isButtonPressed(sfMouseLeft);
    for (i = 0; i < s->txt.textbox_count; i++) {
        tb = &s->textboxes[i];
        handle_interaction(s, tb, mouse, mouse_clicked);
        set_textbox_colors(tb);
        sfText_setString(tb->text, tb->content);
        bounds = sfText_getLocalBounds(tb->text);
        sfText_setPosition(tb->text, (sfVector2f)
            {tb->pos.x + 5, tb->pos.y + (tb->size.y - bounds.height) / 2 - 3});
    }
}
