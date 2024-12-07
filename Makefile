# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 10:14:20 by hni-xuan          #+#    #+#              #
#    Updated: 2024/12/07 11:43:47 by hni-xuan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f 

NAME = push_swap
B_NAME = checker

SRCS_DIR = src
BONUS_DIR = bonus

SRCS_FILES = main.c utils.c check_input.c \
			label_index.c swap.c \
			rotate.c reverse_rotate.c push_swap_algo.c \
			push.c turk_algo.c turk_algo_2.c
				
# BONUS_FILES = bonus.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
# B_SRCS = $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))

OBJS = $(SRCS:.c=.o)
# B_OBJS = $(B_SRCS:.c=.o)

LIBFT_PATH = libft

LIBFT = $(LIBFT_PATH)/libft.a

all : $(NAME)

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

# $(BONUS): $(B_OBJS) $(LIBFT)
# 	$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) -o $(B_NAME)
	
clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean
	
re: fclean all

# bonus : $(B_NAME)
	
.PHONY: all clean fclean re 
	
	
 
