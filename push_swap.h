/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 06:45:27 by yismaail          #+#    #+#             */
/*   Updated: 2023/02/04 02:04:14 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stddef.h>
#include "libft/libft.h"

typedef struct s_stack
{
	int 			value;
	int 			index;
	int				pos;
	int				taret_pos;
	int 			cost_a;
	int				cost_b;
	struct s_stack	*next;
}			t_stack;

//* chack input is valide
void	input_is_valide(char **av);
int		is_digit(char c);
int		is_signe(char c);
int	is_number(char *av);
int	check_duplicate(char *str);
char	*ft_join_all_args(char **av);
int	nb_cmp(const char *s1, const char *s2);


//* initialisation OF value
t_stack *fill_stack_by_value(char *str);
long int	ft_atoi2(char *nbr);
void	free_stack(t_stack **stack);
void	exit_error(t_stack **stack_a, t_stack **stack_b);
void	ft_free_tab(char **arr);
t_stack	*stack_new(int value);
void	stack_add_bottom(t_stack **stack, t_stack *new);
t_stack *get_tail_of_stack(t_stack *stack);
int	get_stack_size(t_stack *stack);

#endif