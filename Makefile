# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nmartins <nmartins@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/18 20:11:18 by nmartins       #+#    #+#                 #
#    Updated: 2019/05/02 20:02:47 by nmartins      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#############
# variables #
#############

# configure
NAME=libgfx.a

OBJECT_NAMES=	\
				gfx_color \
				gfx_primitive_shapes \
				gfx_events \
				gfx_state \
				gfx_image \
				gfx_keys \
				gfx_fps_counter \
				gfx_lines \
				gfx_mouse \
				gfx_math \
				gfx_window \
				gfx_point \
				gfx_vec2 \
				gfx_dimensions \

# do not configure
CC=gcc
MINILIB_LOC=
LIBFT_LOC=
INCLUDES=-I./inc -I./$(LIBFT_LOC) -I./$(MINILIB_LOC)
SRC=./src
OBJ=./.obj
EXTRA=
CFLAGS=-Werror -Wall -Wextra $(EXTRA)
OBJECTS=$(patsubst %, $(OBJ)/%.o, $(MAIN) $(OBJECT_NAMES))
SOURCES=$(patsubst %, $(SRC)/%.c, $(MAIN) $(OBJECT_NAMES))

# colors feel free to add more as you need them
OK_COLOR=\x1b[32;01m
RESET=\x1b[0m
UNDERLINE=\x1b[4m
BLUE=\x1b[36m
RED=\x1b[31m

#########
# rules #
#########
all: $(NAME)

test: $(TEST_NAME)
	@./$(TEST_NAME)

debug:
	$(MAKE) -B "EXTRA=$(EXTRA) -g"

$(NAME): $(OBJECTS)
	@printf " λ Linking $(UNDERLINE)$(BLUE)$@$(RESET)\n"
	@ar rc $@ $(OBJECTS)

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ)
	@printf " λ Making object $(UNDERLINE)$(BLUE)$^$(RESET)\n"
	@$(CC) -c -o $@ $^ $(CFLAGS) $(INCLUDES)

clean:
	@echo "$(RED)Cleaning objects$(RESET)"
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(RED)Cleaning $(NAME) and $(TEST_NAME)$(RESET)"
	@rm -rf $(NAME)
	@rm -rf $(TEST_NAME)

re: fclean all

.SECONDARY: $(OBJECTS)
.PHONY: all debug libft clean fclean re
