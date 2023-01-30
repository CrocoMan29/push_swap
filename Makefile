# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 11:24:02 by yismaail          #+#    #+#              #
#    Updated: 2023/01/30 03:38:06 by yismaail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	cc
CFLAGS		=	-Werror -Wextra -Wall -fsanitize=address
RM			=	rm -rf
SRCS		=	main.c check_args.c check_args_utils.c \
				initialisation.c utils.c stack.c \
				
				
#SRCS_BONUS	=	bonus/pipex_bonus.c \
				bonus/utils_bonus.c \
				bonus/get_next_line_bonus.c \
				bonus/get_next_line_utils_bonus.c \
				libft/ft_split.c \
				libft/ft_substr.c \
				libft/help.c \
				libft/utils.c \
				
OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

$(NAME)		: $(SRCS)
			$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME)
			@ make -C  libft

all			:	$(NAME)
			
clean		:
			$(RM) $(OBJS) $(OBJS_BONUS) $(NAME)

fclean		: clean
			$(RM) $(NAME)

re			: fclean all

#bonus 		: $(SRCS_BONUS)
			$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME)