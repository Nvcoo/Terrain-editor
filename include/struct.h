/*
** EPITECH PROJECT, 2025
** testing
** File description:
** struct
*/
#ifndef INCLUDED_STRUCT_H
    #define INCLUDED_STRUCT_H

    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Types.h>
    #include <SFML/System/Vector2.h>

typedef enum {
    TOOL_RAISE,
    TOOL_LOWER,
    TOOL_FLATTEN,
    TOOL_RESET,
    TOOL_COUNT
} tool_type_t;

typedef enum {
    BTN_IDLE,
    BTN_HOVER,
    BTN_CLICKED
} button_state_t;

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
} background_t;

typedef struct {
    sfRectangleShape *shape;
    sfText *text;
    sfVector2f pos;
    sfVector2f size;
    button_state_t state;
    int tool_id;
} ui_button_t;

typedef struct {
    int height;
    sfColor color;
    sfVector2f iso_pos;
    int selected;
} tile_t;

typedef struct {
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape* shape;
    sfText* text;
    char content[16];
    int is_active;
    int cursor_pos;
} textbox_t;

typedef struct {
    sfText *help_text;
    sfText *brush_size_text;
    char help_string[256];
    int textbox_count;
} texts_t;

typedef struct {
    background_t *bg;
    sfRenderWindow* window;
    sfFont *font;
    sfClock *clock;
    sfVector2u window_size;
    float zoom;
} main_t;

typedef struct {
    int button_count;
    int brush_size;
    int selected_x;
    int selected_y;
    int brush_button_count;
    int mouse_button_pressed;
} extra_t;

typedef struct {
    main_t mn;
    tile_t **map;
    int map_w;
    int map_h;
    sfVector2f camera_offset;
    ui_button_t *buttons;
    tool_type_t current_tool;
    sfVector2i mouse_pos;
    ui_button_t *brush_buttons;
    textbox_t *textboxes;
    ui_button_t *apply_button;
    texts_t txt;
    extra_t ext;
    sfTexture *grass_texture;
} game_state_t;

typedef struct {
    game_state_t *s;
    float min_dist;
    sfVector2i tile;
} tile_info_t;

#endif
