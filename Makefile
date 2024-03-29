# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 16:11:15 by jdoukhan          #+#    #+#              #
#    Updated: 2024/02/01 17:37:46 by jdoukhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# if error suppressed then add XSizeHints    hints = {};
# inside mlx_int_anti_resize_win at mlx_int_anti_resize_win.c

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME = so_long
CFLAGS = -Wall -Wextra -Werror -g3
CC = cc

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

COMMON_SOURCES = load_main_textures.c map_rendering.c \
	spwn_image.c sprite_init.c sprite_emoji_init.c \
	draw_fg.c draw_bg.c  transparency.c \
	keys_main.c utils.c free_all.c kill_all_sprites.c \
	map_checks.c map_check_borders.c 

M_SOURCES = main.c move_player.c key_handler.c events.c win_scene.c \
	lose_scene.c no_pnj.c
B_SOURCES = main_bonus.c clocking.c hud.c update.c events.c win_scene.c \
	lose_scene.c start_scene.c move_entities.c key_handler.c draw_pnj.c

################################################################################
#                                  ExtLib Body                                 #
################################################################################

INCLUDES = -I./minilibx-linux -I./includes -I./minilibft
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -Lminilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11
MINILIBFT_DIR = ./minilibft
MINILIBFT = $(MINILIBFT_DIR)/minilibft.a
MINILIBFT_FLAGS = -Lminilibft -lminilibft

################################################################################
#                                 Makefile Body                                #
################################################################################

PM_SOURCES = $(addprefix common/, $(COMMON_SOURCES)) \
	$(addprefix mandatory/, $(M_SOURCES))
PB_SOURCES = $(addprefix common/, $(COMMON_SOURCES)) \
	$(addprefix bonus/, $(B_SOURCES))
SRCS = $(addprefix srcs/, $(PM_SOURCES))
OBJS = $(SRCS:srcs/%.c=objs/%.o)
B_NAME = $(NAME)_bonus
B_SRCS = $(addprefix srcs/, $(PB_SOURCES))
B_OBJS = $(B_SRCS:srcs/%.c=objs/%.o)

all: $(MLX_LIB) $(MINILIBFT) $(NAME)

bonus: $(MLX_LIB) $(MINILIBFT) $(B_NAME)

objs/%.o : srcs/%.c
	@$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(B_NAME) : $(B_OBJS)
	@rm -rf $(NAME)
	@$(CC) $(B_SRCS) $(CFLAGS) -o $(NAME) $(MLX_FLAGS) $(MINILIBFT_FLAGS) $(INCLUDES)
	@echo "\033[0;32mBonus part compiled ✔️\033[1;37m"

$(NAME) : $(OBJS)
	@$(CC) $(SRCS) $(CFLAGS) -o $(NAME) $(MLX_FLAGS) $(MINILIBFT_FLAGS) $(INCLUDES)
	@echo "\033[0;32mMandatory part compiled ✔️\033[1;37m"

$(MLX_LIB): $(MLX_DIR)
	@make -C $(MLX_DIR) --no-print-directory

$(MLX_DIR):
	@git clone https://github.com/42Paris/minilibx-linux

$(MINILIBFT):
	@mkdir -p objs objs/common objs/mandatory objs/bonus minilibft/objs
	@make -C $(MINILIBFT_DIR) --no-print-directory

clean:
	@rm -rf $(OBJS) $(B_OBJS)
	@echo "\033[0;33mCleaned .o files ✔️\033[1;37m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;91mCleaned exe ✔️\033[1;37m"

ffclean: fclean
	@rm -rf $(MLX_DIR)
	@make -C minilibft fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re bonus ffclean
