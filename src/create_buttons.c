/*
** EPITECH PROJECT, 2025
** testing
** File description:
** create_buttons
*/

#include "utils.h"
#include "struct.h"

static sfRectangleShape *create_button_shape(sfVector2f pos, sfVector2f size,
    sfColor fill_color)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setPosition(shape, pos);
    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setFillColor(shape, fill_color);
    sfRectangleShape_setOutlineThickness(shape, 2);
    sfRectangleShape_setOutlineColor(shape, sfWhite);
    return shape;
}

static sfText *create_button_text(const char *text_str, sfFont *font,
    unsigned int char_size)
{
    sfText *text = sfText_create();

    if (font)
        sfText_setFont(text, font);
    sfText_setString(text, text_str);
    sfText_setCharacterSize(text, char_size);
    sfText_setFillColor(text, sfWhite);
    return text;
}

static void center_text_on_button(sfText *text, sfVector2f btn_pos,
    sfVector2f btn_size, int y_offset)
{
    sfFloatRect bounds = sfText_getLocalBounds(text);
    sfVector2f text_pos = {
        btn_pos.x + (btn_size.x - bounds.width) / 2,
        btn_pos.y + (btn_size.y - bounds.height) / 2 + y_offset
    };

    sfText_setPosition(text, text_pos);
}

static void create_tool_buttons(game_state_t *s)
{
    ui_button_t *b;
    const char *names[] = {"Raise", "Lower", "Flat", "Reset"};
    const sfColor colors[] = {
        {100, 150, 100, 255},
        {150, 100, 100, 255},
        {150, 150, 100, 255}, {100, 100, 150, 255}
    };

    s->ext.button_count = TOOL_COUNT;
    s->buttons = malloc(s->ext.button_count * sizeof(ui_button_t));
    for (int i = 0; i < s->ext.button_count; i++) {
        b = &s->buttons[i];
        b->pos = (sfVector2f){10, 50 + i * 60};
        b->size = (sfVector2f){150, 40};
        b->state = BTN_IDLE;
        b->tool_id = i;
        b->shape = create_button_shape(b->pos, b->size, colors[i]);
        b->text = create_button_text(names[i], s->mn.font, 30);
        center_text_on_button(b->text, b->pos, b->size, -5);
    }
}

static void create_brush_button(ui_button_t *btn, sfVector2f pos,
    const char *text_str, int tool_id)
{
    btn->pos = pos;
    btn->size = (sfVector2f){30, 30};
    btn->state = BTN_IDLE;
    btn->tool_id = tool_id;
    btn->shape = create_button_shape(pos, btn->size,
        (sfColor){80, 80, 80, 255});
    btn->text = sfText_create();
    sfText_setString(btn->text, text_str);
    sfText_setCharacterSize(btn->text, 20);
    sfText_setFillColor(btn->text, sfWhite);
}

static void create_brush_buttons(game_state_t *s)
{
    s->brush_buttons = malloc(2 * sizeof(ui_button_t));
    s->ext.brush_button_count = 2;
    create_brush_button(&s->brush_buttons[0], (sfVector2f){10, 350}, "Q", -1);
    create_brush_button(&s->brush_buttons[1], (sfVector2f){130, 350}, "E", -2);
    if (s->mn.font) {
        sfText_setFont(s->brush_buttons[0].text, s->mn.font);
        sfText_setFont(s->brush_buttons[1].text, s->mn.font);
    }
    center_text_on_button(s->brush_buttons[0].text, s->brush_buttons[0].pos,
        s->brush_buttons[0].size, -3);
    center_text_on_button(s->brush_buttons[1].text,
        s->brush_buttons[1].pos, s->brush_buttons[1].size, -3);
}

static void create_brush_size_text(game_state_t *s)
{
    s->txt.brush_size_text = create_button_text("", s->mn.font, 18);
    sfText_setPosition(s->txt.brush_size_text, (sfVector2f){45, 355});
}

void create_buttons(game_state_t *s)
{
    create_tool_buttons(s);
    create_brush_buttons(s);
    create_brush_size_text(s);
}
