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
		./src/handling/handle_text_input.c \
		./src/ui/button_colors.c \
		./src/ui/create_buttons.c \
		./src/ui/render_ui.c \
		./src/ui/res_view.c \
		./src/ui/update_ui.c \
		./src/ui/textboxes/create_textboxes.c \
		./src/ui/textboxes/init_textbox.c \
		./src/ui/textboxes/update_textboxes.c \
		./src/map/draw_map.c \
		./src/map/draw_textured_tiles.c \
		./src/map/get_altitude_color.c \
		./src/map/project_iso_point.c \
		./src/map/screen_to_tile.c \
		./src/map/world_to_screen.c \
		./src/core/apply_tool.c \
		./src/core/cleanup_game.c \
		./src/core/init_game.c \
		./src/core/recreate_map.c \
		./src/utils/utils.c \
		./src/save/save_map.c \

OBJ = $(SRC:.c=.o)

NAME = world

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)
		@echo "Compiled successfully!"
		@echo "Binary: $(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "CC $<"

clean:
		@rm -f $(OBJ)
		@echo "Object files removed"

fclean: clean
		@rm -f $(NAME)
		@echo "Binary removed"

re:	fclean all
