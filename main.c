/*
** EPITECH PROJECT, 2025
** testing
** File description:
** main
*/

#include "utils.h"
#include "struct.h"

void update_game(game_state_t *s)
{
    update_ui(s);
    for (int y = 0; y < s->map_h; y++)
        for (int x = 0; x < s->map_w; x++)
            s->map[y][x].selected = 0;
    if (s->ext.selected_x >= 0 && s->ext.selected_y >= 0)
        s->map[s->ext.selected_y][s->ext.selected_x].selected = 1;
    sfText_setString(s->txt.help_text, s->txt.help_string);
}

void render_game(game_state_t *s)
{
    sfRenderWindow_clear(s->mn.window, sfBlack);
    sfRenderWindow_drawSprite(s->mn.window, s->mn.bg->sprite, NULL);
    draw_map(s->mn.window, s);
    render_ui(s);
    sfRenderWindow_display(s->mn.window);
}

int main(void)
{
    background_t bg;
    game_state_t state;

    init_game(&state);
    sfRenderWindow_setFramerateLimit(state.mn.window, 60);
    bg = create_background(state.mn.window);
    state.mn.bg = &bg;
    while (sfRenderWindow_isOpen(state.mn.window)) {
        handle_events(&state);
        update_game(&state);
        render_game(&state);
    }
    cleanup_game(&state);
    destroy_background(bg);
    return 0;
}
