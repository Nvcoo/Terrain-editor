/*
** EPITECH PROJECT, 2025
** testing
** File description:
** init_game
*/

#include "utils.h"
#include "struct.h"

void init_window_and_graphics(game_state_t *s)
{
    sfVideoMode mode = (sfVideoMode){800, 600, 32};

    s->mn.window = sfRenderWindow_create(mode, "My World - Terrain Editor",
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(s->mn.window, 60);
    s->mn.window_size = sfRenderWindow_getSize(s->mn.window);
    s->mn.font = sfFont_createFromFile("assets/Pixar.ttf");
    if (!s->mn.font)
        printf("Could not load Pixar.ttf\n");
    s->mn.clock = sfClock_create();
}

static void init_textures(game_state_t *s)
{
    s->grass_texture = sfTexture_createFromFile("assets/terr.png", NULL);
    if (!s->grass_texture)
        printf("Could not load terr.png texture\n");
}

void init_map_memory(game_state_t *s)
{
    s->map_w = MAP_SIZE;
    s->map_h = MAP_SIZE;
    s->map = malloc(s->map_h * sizeof(tile_t *));
    for (int y = 0; y < s->map_h; y++)
        s->map[y] = malloc(s->map_w * sizeof(tile_t));
}

void init_tile_data(game_state_t *s)
{
    for (int y = 0; y < s->map_h; y++) {
        for (int x = 0; x < s->map_w; x++)
            s->map[y][x] = (tile_t){0, sfGreen,
                project_iso_point(x * TILE_SPACING, y * TILE_SPACING, 0), 0};
    }
}

void init_camera_and_tools(game_state_t *s)
{
    s->camera_offset = (sfVector2f){
    (float)s->mn.window_size.x / 2 - (float)UI_WIDTH / 2,
    (float)s->mn.window_size.y / 2};
    s->mn.zoom = 1.0f;
    s->current_tool = TOOL_RAISE;
    s->ext.brush_size = 1;
    s->ext.selected_x = -1;
    s->ext.selected_y = -1;
    s->ext.mouse_button_pressed = 0;
}

static void init_ui_components(game_state_t *s)
{
    create_buttons(s);
    create_textboxes(s);
    s->txt.help_text = sfText_create();
    if (s->mn.font)
        sfText_setFont(s->txt.help_text, s->mn.font);
    sfText_setCharacterSize(s->txt.help_text, 30);
    sfText_setFillColor(s->txt.help_text, sfWhite);
    sfText_setPosition(s->txt.help_text, (sfVector2f){UI_WIDTH + 10,
    s->mn.window_size.y - 40});
    strcpy(s->txt.help_string, "Select a tool and click on the terrain");
}

void init_game(game_state_t *s)
{
    init_window_and_graphics(s);
    init_textures(s);
    init_map_memory(s);
    init_tile_data(s);
    init_camera_and_tools(s);
    init_ui_components(s);
}
