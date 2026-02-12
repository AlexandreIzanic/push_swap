# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2025/12/20 12:00:00 by alex              #+#    #+#             #
#    Updated: 2025/12/20 12:00:00 by alex             ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= push_swap.c \
			utils.c \
			operations.c 
OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR)

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
			$(MAKE) -C $(LIBFT_DIR) clean
			rm -f $(OBJS)

fclean:		clean
			$(MAKE) -C $(LIBFT_DIR) fclean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
