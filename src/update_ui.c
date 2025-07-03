/*
** EPITECH PROJECT, 2025
** testing
** File description:
** update_ui
*/

#include "utils.h"
#include "struct.h"

static void mouse_tools(game_state_t *s, ui_button_t *b, int mouse_clicked,
    const char *help[])
{
    if (mouse_clicked && !s->ext.mouse_button_pressed) {
        b->state = BTN_CLICKED;
        s->current_tool = b->tool_id;
        strcpy(s->txt.help_string, help[b->tool_id]);
    }
    if (!mouse_clicked)
        b->state = BTN_HOVER;
}

void handle_tool_buttons(game_state_t *s, sfVector2i mouse, int mouse_clicked)
{
    const char *help[] = {
        "Raise tool: Click to raise terrain",
        "Lower tool: Click to lower terrain",
        "Flatten tool: Click to flatten terrain",
        "Reset tool: Click to reset terrain to ground level"
    };
    sfColor color;
    ui_button_t *b;

    for (int i = 0; i < s->ext.button_count; i++) {
        b = &s->buttons[i];
        if (mouse.x >= b->pos.x && mouse.x <= b->pos.x + b->size.x &&
            mouse.y >= b->pos.y && mouse.y <= b->pos.y + b->size.y) {
                mouse_tools(s, b, mouse_clicked, help);
        } else
            b->state = BTN_IDLE;
        color = get_button_color(b->state,
            (int)s->current_tool == (int)b->tool_id);
        sfRectangleShape_setFillColor(b->shape, color);
    }
}

static void handle_brush_size_change(game_state_t *s, int tool_id)
{
    if (tool_id == -1) {
        if (s->ext.brush_size > 0)
            s->ext.brush_size--;
        strcpy(s->txt.help_string, "Brush size decreased");
    }
    if (tool_id == -2) {
        if (s->ext.brush_size < 5)
            s->ext.brush_size++;
        strcpy(s->txt.help_string, "Brush size increased");
    }
}

static void mouse_brush(game_state_t *s, ui_button_t *b, int mouse_clicked)
{
    if (mouse_clicked && !s->ext.mouse_button_pressed) {
        b->state = BTN_CLICKED;
        handle_brush_size_change(s, b->tool_id);
    }
    if (!mouse_clicked)
        b->state = BTN_HOVER;
}

void handle_brush_buttons(game_state_t *s, sfVector2i mouse, int mouse_clicked)
{
    sfColor color;
    ui_button_t *b;

    for (int i = 0; i < s->ext.brush_button_count; i++) {
        b = &s->brush_buttons[i];
        if (is_mouse_over_button(mouse, b))
            mouse_brush(s, b, mouse_clicked);
        else
            b->state = BTN_IDLE;
        color = get_brush_button_color(b->state);
        sfRectangleShape_setFillColor(b->shape, color);
    }
}

static void apply_map_size_change(game_state_t *s, int new_width,
    int new_height)
{
    if (new_width > 0 && new_width <= 100 &&
        new_height > 0 && new_height <= 100) {
        recreate_map(s, new_width, new_height);
        strcpy(s->txt.help_string, "Map size updated successfully");
    } else
        strcpy(s->txt.help_string, "Invalid map size (1-100 allowed)");
}

void handle_apply_button(game_state_t *s, sfVector2i mouse, int mouse_clicked)
{
    ui_button_t *b = s->apply_button;
    int new_width;
    int new_height;
    sfColor color;

    if (mouse.x >= b->pos.x && mouse.x <= b->pos.x + b->size.x &&
        mouse.y >= b->pos.y && mouse.y <= b->pos.y + b->size.y) {
        if (mouse_clicked && !s->ext.mouse_button_pressed) {
            b->state = BTN_CLICKED;
            new_width = atoi(s->textboxes[0].content);
            new_height = atoi(s->textboxes[1].content);
            apply_map_size_change(s, new_width, new_height);
        }
        if (!mouse_clicked)
            b->state = BTN_HOVER;
    } else
        b->state = BTN_IDLE;
    color = get_apply_button_color(b->state);
    sfRectangleShape_setFillColor(b->shape, color);
}

void update_ui(game_state_t *s)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(s->mn.window);
    int mouse_clicked = sfMouse_isButtonPressed(sfMouseLeft);
    char brush_text[32];

    update_background(s->mn.bg, s->mn.window);
    handle_tool_buttons(s, mouse, mouse_clicked);
    handle_brush_buttons(s, mouse, mouse_clicked);
    handle_apply_button(s, mouse, mouse_clicked);
    update_textboxes(s);
    s->ext.mouse_button_pressed = mouse_clicked;
    snprintf(brush_text, sizeof(brush_text), " Size: %d", s->ext.brush_size);
    sfText_setString(s->txt.brush_size_text, brush_text);
}
