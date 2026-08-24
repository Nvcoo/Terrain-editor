/*
** EPITECH PROJECT, 2025
** testing
** File description:
** handle_text_input
*/

#include "utils.h"
#include "struct.h"

void handle_text_input(game_state_t *s, sfUint32 input_char)
{
    textbox_t *tb = NULL;

    for (int i = 0; i < s->txt.textbox_count; i++) {
        if (s->textboxes[i].is_active) {
            tb = &s->textboxes[i];
            break;
        }
    }
    if (!tb)
        return;
    if (input_char == 8) {
        if (tb->cursor_pos > 0) {
            tb->cursor_pos--;
            tb->content[tb->cursor_pos] = '\0';
        }
    } else if (input_char >= '0' && input_char <= '9' && tb->cursor_pos < 15) {
        tb->content[tb->cursor_pos] = (char)input_char;
        tb->cursor_pos++;
        tb->content[tb->cursor_pos] = '\0';
    }
}
