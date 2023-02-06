/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:43:12 by yismaail          #+#    #+#             */
/*   Updated: 2023/02/06 20:23:03 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_tail_of_stack(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	do_ra_ch(t_stack **stack_a)
{
	if (!*stack_a)
		return ;
	rotate(stack_a);
}

void	do_rb_ch(t_stack **stack_b)
{
	if (!*stack_b)
		return ;
	rotate(stack_b);
}

void	do_rr_ch(t_stack **stack_a, t_stack **stack_b)
{
	do_ra_ch(stack_a);
	do_rb_ch(stack_b);
}

char	*ft_join_all_args(char **av)
{
	int		i;
	char	*first_join;

	i = 1;
	first_join = NULL;
	while (av[i])
	{
		first_join = ft_strjoin(first_join, " ");
		first_join = ft_strjoin(first_join, av[i]);
		i++;
	}
	return (first_join);
}
