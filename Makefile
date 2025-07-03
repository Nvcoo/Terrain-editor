##
## EPITECH PROJECT, 2024
## Untitled (Workspace)
## File description:
## makefile
##

.PHONY: all clean fclean re

CC = gcc

CFLAGS = -Wall -Wextra -g -I./include

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

SRC =	./main.c \
		./src/textures/create_background.c \
		./src/textures/destroy_background.c \
		./src/textures/update_background.c \
		./src/handling/handle_effects.c \
		./src/handling/handle_events.c \
		./src/handling/handle_keys.c \
		./src/handling/handle_mouse.c \
		./src/textboxes/create_textboxes.c \
		./src/textboxes/init_textbox.c \
		./src/textboxes/update_textboxes.c \
		./src/apply_tool.c \
		./src/button_colors.c \
		./src/cleanup_game.c \
		./src/create_buttons.c \
		./src/draw_map.c \
		./src/get_altitude_color.c \
		./src/handle_text_input.c \
		./src/init_game.c \
		./src/project_iso_point.c \
		./src/recreate_map.c \
		./src/render_ui.c \
		./src/res_view.c \
		./src/screen_to_tile.c \
		./src/update_ui.c \
		./src/utils.c \
		./src/world_to_screen.c \
		./src/save/save_map.c \
		./src/draw_textured_tiles.c \

OBJ = $(SRC:.c=.o)

NAME = my_world

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all
