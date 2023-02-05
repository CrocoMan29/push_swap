/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 06:45:27 by yismaail          #+#    #+#             */
/*   Updated: 2023/02/05 09:09:39 by yismaail         ###   ########.fr       */
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
	int				target_pos;
	int 			cost_a;
	int				cost_b;
	struct s_stack	*next;
}			t_stack;

//* chack input is valide
void	input_is_valide(char **av);
int		is_digit(char c);
int		is_signe(char c);
int	nb_abs(int nb);
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
t_stack *get_befor_tail_stack(t_stack *stack);
int	get_stack_size(t_stack *stack);
void	assigne_index(t_stack *stack, int size_stack);

//*instarction
void do_sa(t_stack **stack_a);
void do_sb(t_stack **stack_b);
void do_ss(t_stack **stack_a, t_stack **stack_b);
void do_ra(t_stack **stack_a);
void do_rb(t_stack **stack_b);
void do_rr(t_stack **stack_a, t_stack **stack_b);
void do_rra(t_stack **stack_a);
void do_rrb(t_stack **stack_b);
void do_rrr(t_stack **stack_a, t_stack **stack_b);
void do_pa(t_stack **stack_a, t_stack **stack_b);
void do_pb(t_stack **stack_a, t_stack **stack_b);

//*sorting
void sort(t_stack **stack_a, t_stack **stack_b);
void sort_of_3(t_stack**stack);
int get_lowest_index_position(t_stack **stack);
void get_target_position(t_stack **a, t_stack **b);
void	get_cost(t_stack **stack_a, t_stack **stack_b);
void	do_ultimate_move(t_stack **stack_a, t_stack **stack_b);
void do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
int is_sorted(t_stack *stack);


#endif