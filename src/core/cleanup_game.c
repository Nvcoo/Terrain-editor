/*
** EPITECH PROJECT, 2025
** testing
** File description:
** cleanup_game
*/

#include "utils.h"
#include "struct.h"

void final_cleanup(game_state_t *s)
{
    if (s->apply_button)
        free(s->apply_button);
    if (s->txt.help_text)
        sfText_destroy(s->txt.help_text);
    if (s->txt.brush_size_text)
        sfText_destroy(s->txt.brush_size_text);
    if (s->mn.font)
        sfFont_destroy(s->mn.font);
    if (s->mn.clock)
        sfClock_destroy(s->mn.clock);
    if (s->grass_texture)
        sfTexture_destroy(s->grass_texture);
    if (s->mn.window)
        sfRenderWindow_destroy(s->mn.window);
}

void cleanup_textboxes(game_state_t *s)
{
    for (int i = 0; i < s->txt.textbox_count; i++) {
        if (s->textboxes[i].shape)
            sfRectangleShape_destroy(s->textboxes[i].shape);
        if (s->textboxes[i].text)
            sfText_destroy(s->textboxes[i].text);
    }
}

void cleanup_map(game_state_t *s)
{
    for (int y = 0; y < s->map_h; y++) {
        if (s->map[y])
            free(s->map[y]);
    }
}

void cleanup_game(game_state_t *s)
{
    if (s->map) {
        cleanup_map(s);
        free(s->map);
    }
    if (s->buttons)
        free(s->buttons);
    if (s->brush_buttons)
        free(s->brush_buttons);
    if (s->textboxes) {
        cleanup_textboxes(s);
        free(s->textboxes);
    }
    final_cleanup(s);
}
