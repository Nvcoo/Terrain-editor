/*
** EPITECH PROJECT, 2025
** testing
** File description:
** render_ui
*/

#include "utils.h"
#include "struct.h"

void render_panel(game_state_t *s)
{
    sfRectangleShape *panel = sfRectangleShape_create();

    sfRectangleShape_setSize(panel, (sfVector2f){UI_WIDTH,
        s->mn.window_size.y});
    sfRectangleShape_setPosition(panel, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(panel, (sfColor){40, 40, 40, 200});
    sfRenderWindow_drawRectangleShape(s->mn.window, panel, NULL);
    sfRectangleShape_destroy(panel);
}

void render_title(game_state_t *s)
{
    sfText *title;

    if (!s->mn.font)
        return;
    title = sfText_create();
    sfText_setFont(title, s->mn.font);
    sfText_setString(title, "My World");
    sfText_setCharacterSize(title, 24);
    sfText_setFillColor(title, sfWhite);
    sfText_setPosition(title, (sfVector2f){10, 10});
    sfRenderWindow_drawText(s->mn.window, title, NULL);
    sfText_destroy(title);
}

static void render_buttons(game_state_t *s)
{
    for (int i = 0; i < s->ext.button_count; i++) {
        sfRenderWindow_drawRectangleShape(s->mn.window, s->buttons[i].shape,
            NULL);
        sfRenderWindow_drawText(s->mn.window, s->buttons[i].text, NULL);
    }
}

void render_brush(game_state_t *s)
{
    sfText *brush_label;

    if (s->mn.font) {
        brush_label = sfText_create();
        sfText_setFont(brush_label, s->mn.font);
        sfText_setString(brush_label, "Brush:");
        sfText_setCharacterSize(brush_label, 30);
        sfText_setFillColor(brush_label, sfWhite);
        sfText_setPosition(brush_label, (sfVector2f){10, 300});
        sfRenderWindow_drawText(s->mn.window, brush_label, NULL);
        sfText_destroy(brush_label);
    }
    for (int i = 0; i < s->ext.brush_button_count; i++) {
        sfRenderWindow_drawRectangleShape(s->mn.window,
            s->brush_buttons[i].shape, NULL);
        sfRenderWindow_drawText(s->mn.window, s->brush_buttons[i].text, NULL);
    }
}

static void render_controls(game_state_t *s)
{
    char *controls_text =
        "Controls:\n""--------------------\n""Arrows:\nMove cam\n"
        "--------------------\n"
        "+/-: Zoom\n"
        "--------------------\n"
        "1-4: tools\n"
        "--------------------\n"
        "Q/E: Size\n"
        "--------------------\n"
        "Mouse:\nEdit map\n"
        "--------------------";
    sfText *ctrl = sfText_create();

    sfText_setFont(ctrl, s->mn.font);
    sfText_setString(ctrl, controls_text);
    sfText_setCharacterSize(ctrl, 24);
    sfText_setFillColor(ctrl, sfWhite);
    sfText_setPosition(ctrl, (sfVector2f){10, 400});
    sfRenderWindow_drawText(s->mn.window, ctrl, NULL);
    sfText_destroy(ctrl);
}

void render_textboxes(game_state_t *s)
{
    for (int i = 0; i < s->txt.textbox_count; i++) {
        sfRenderWindow_drawRectangleShape(s->mn.window, s->textboxes[i].shape,
            NULL);
        sfRenderWindow_drawText(s->mn.window, s->textboxes[i].text, NULL);
    }
    sfRenderWindow_drawRectangleShape(s->mn.window, s->apply_button->shape,
        NULL);
    sfRenderWindow_drawText(s->mn.window, s->apply_button->text, NULL);
}

void render_ui(game_state_t *s)
{
    render_panel(s);
    render_title(s);
    render_buttons(s);
    render_brush(s);
    sfRenderWindow_drawText(s->mn.window, s->txt.brush_size_text, NULL);
    if (s->mn.font)
        sfRenderWindow_drawText(s->mn.window, s->txt.help_text, NULL);
    render_controls(s);
    render_textboxes(s);
}
