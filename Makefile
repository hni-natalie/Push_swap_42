# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hni-xuan <hni-xuan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 10:14:20 by hni-xuan          #+#    #+#              #
#    Updated: 2024/12/09 10:42:09 by hni-xuan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f 

NAME = push_swap
B_NAME = checker

SRCS_DIR = src
BONUS_DIR = bonus

SRCS = src/main.c src/utils.c src/check_input.c \
		src/label_index.c src/swap.c \
		src/rotate.c src/reverse_rotate.c src/push_swap_algo.c \
		src/push.c src/turk_algo.c src/turk_algo_2.c
				
B_SRCS = bonus/bonus.c bonus/check_input.c bonus/label_index.c \
			bonus/main_func.c bonus/push.c bonus/reverse_rotate.c \
			bonus/swap.c bonus/rotate.c bonus/utils.c

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

LIBFT_PATH = libft

LIBFT = $(LIBFT_PATH)/libft.a

all : $(NAME)

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(B_NAME): $(B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) -o $(B_NAME)
	
clean:
	$(RM) $(OBJS) $(B_OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME) $(B_NAME)
	make -C $(LIBFT_PATH) fclean
	
re: fclean all

bonus : $(B_NAME)
	
.PHONY: all clean fclean re 
	
	
 
