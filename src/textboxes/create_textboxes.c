/*
** EPITECH PROJECT, 2025
** testing
** File description:
** create_textboxes
*/

#include "utils.h"
#include "struct.h"

void create_single_textbox(textbox_t *tb, sfVector2f pos, int value,
    sfFont *font)
{
    tb->pos = pos;
    tb->size = (sfVector2f){60, 30};
    tb->is_active = 0;
    tb->cursor_pos = 0;
    snprintf(tb->content, sizeof(tb->content), "%d", value);
    init_textbox_shape(tb);
    init_textbox_text(tb, font);
}

void init_apply_button_shape(ui_button_t *btn)
{
    btn->shape = sfRectangleShape_create();
    sfRectangleShape_setPosition(btn->shape, btn->pos);
    sfRectangleShape_setSize(btn->shape, btn->size);
    sfRectangleShape_setFillColor(btn->shape, (sfColor){100, 150, 100, 255});
    sfRectangleShape_setOutlineThickness(btn->shape, 2);
    sfRectangleShape_setOutlineColor(btn->shape, sfWhite);
}

void init_apply_button_text(ui_button_t *btn, sfFont *font)
{
    sfFloatRect bounds;

    btn->text = sfText_create();
    if (font)
        sfText_setFont(btn->text, font);
    sfText_setString(btn->text, "Apply Size");
    sfText_setCharacterSize(btn->text, 18);
    sfText_setFillColor(btn->text, sfWhite);
    bounds = sfText_getLocalBounds(btn->text);
    sfText_setPosition(btn->text, (sfVector2f){
        btn->pos.x + (btn->size.x - bounds.width) / 2,
        btn->pos.y + (btn->size.y - bounds.height) / 2 - 3
    });
}

void create_apply_button(game_state_t *s)
{
    s->apply_button = malloc(sizeof(ui_button_t));
    s->apply_button->pos = (sfVector2f){10, 840};
    s->apply_button->size = (sfVector2f){140, 30};
    s->apply_button->state = BTN_IDLE;
    s->apply_button->tool_id = -10;
    init_apply_button_shape(s->apply_button);
    init_apply_button_text(s->apply_button, s->mn.font);
}

void create_textboxes(game_state_t *s)
{
    s->txt.textbox_count = 2;
    s->textboxes = malloc(s->txt.textbox_count * sizeof(textbox_t));
    create_single_textbox(&s->textboxes[0], (sfVector2f){10, 800},
        s->map_w, s->mn.font);
    create_single_textbox(&s->textboxes[1], (sfVector2f){90, 800},
        s->map_h, s->mn.font);
    create_apply_button(s);
}
