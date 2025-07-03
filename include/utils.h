/*
** EPITECH PROJECT, 2025
** testing
** File description:
** utils
*/
#ifndef INCLUDED_UTILS_H
    #define INCLUDED_UTILS_H

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <math.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include "struct.h"
    #include <time.h>

    #define WINDOW_W 1200
    #define WINDOW_H 800
    #define MAP_SIZE 32
    #define TILE_SPACING 32
    #define ANGLE_X (45.0f * M_PI / 180.0f)
    #define ANGLE_Y (35.0f * M_PI / 180.0f)
    #define MAX_HEIGHT 15
    #define UI_WIDTH 200

sfVector2f project_iso_point(int x, int y, int z);
background_t create_background(sfRenderWindow *window);
void destroy_background(background_t bg);
void update_background(background_t *bg, sfRenderWindow *window);
void res_view(game_state_t *s);
void create_textboxes(game_state_t *s);
void recreate_map(game_state_t *s, int new_width, int new_height);
void create_buttons(game_state_t *s);
void init_game(game_state_t *s);
void update_ui(game_state_t *s);
void update_textboxes(game_state_t *s);
void render_ui(game_state_t *s);
void cleanup_game(game_state_t *s);
void draw_map(sfRenderWindow *w, game_state_t *s);
void draw_textured_tiles(sfRenderWindow *w, game_state_t *s);
sfVector2f world_to_screen(sfVector2f world, game_state_t *s);
sfColor get_altitude_color(int height, int is_selected);
void handle_events(game_state_t *s);
void handle_text_input(game_state_t *s, sfUint32 unicode);
void apply_tool(game_state_t *s, int tx, int ty);
sfVector2i screen_to_tile(sfVector2i screen, game_state_t *s);
int is_mouse_over_button(sfVector2i mouse, ui_button_t *button);
sfColor get_button_color(button_state_t state, int is_current_tool);
sfColor get_brush_button_color(button_state_t state);
sfColor get_apply_button_color(button_state_t state);
void handle_mouse_wheel(game_state_t *s, sfEvent *e);
void handle_mouse_buttons(game_state_t *s, sfEvent *e);
void handle_keyboard(game_state_t *s, sfEvent *e);
void handle_text(game_state_t *s, sfEvent *e);
void handle_brush(game_state_t *s, sfKeyCode key);
void handle_tools(game_state_t *s, sfKeyCode key);
void init_textbox_text(textbox_t *tb, sfFont *font);
void init_textbox_shape(textbox_t *tb);
int save_map(game_state_t *s, const char *filename);

#endif
