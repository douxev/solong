# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 11:35:01 by jdoukhan          #+#    #+#              #
#    Updated: 2024/01/12 17:31:45 by jdoukhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libminilibft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_printf.c ft_nbase.c ft_ptr.c gnl.c gnl_utils.c
OBJECTS = $(SOURCES:%.c=objs/%.o)

all: $(NAME)
	@sleep 0

objs/%.o:%.c 
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)
	@echo "\033[0;33mMinilibft compiled ✔️\033[1;37m"

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;91mCleaned minilibft ✔️\033[1;37m"

re: fclean all

.PHONY: all clean fclean re
