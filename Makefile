# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 11:24:02 by yismaail          #+#    #+#              #
#    Updated: 2023/02/06 20:52:14 by yismaail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
NAME_BONUS	=	checker
CC			=	cc
CFLAGS		=	-Werror -Wextra -Wall 
RM			=	rm -rf
SRCS		=	main.c check_args.c check_args_utils.c \
				initialisation.c utils.c \
				swap.c stack.c sort.c sort_of_3.c \
				rotate.c reverse_rotate.c push.c \
				position.c do_move.c cost.c\
				
				
SRCS_BONUS	=	bonus/push_swap_b.c bonus/get_next_line_bonus.c \
				bonus/get_next_line_utils_bonus.c bonus/push.c \
				bonus/reverse_rotate.c bonus/rotate.c \
				bonus/swap.c bonus/utils.c bonus/stack.c  bonus/blabla.c \
				
				
OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

all			:	$(NAME)
bonus			:	$(NAME_BONUS)

$(NAME)		: $(OBJS)
			make -C libft
			$(CC)  $(OBJS) libft/libft.a -o $(NAME)
			
			
$(NAME_BONUS) 	: $(OBJS_BONUS)
				make -C libft
				$(CC) $(CFLAGS) $(OBJS_BONUS) libft/libft.a -o $(NAME_BONUS)

clean		:
			$(RM) $(OBJS) $(OBJS_BONUS)
			make clean -C libft

fclean		: clean
			$(RM) $(NAME) $(NAME_BONUS)
			make fclean -C libft

re			: fclean all
