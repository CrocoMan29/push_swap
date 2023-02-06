/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:42:30 by yismaail          #+#    #+#             */
/*   Updated: 2023/02/06 20:21:21 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	do_sa_ch(t_stack **stack_a)
{
	if (!*stack_a)
		return ;
	swap(*stack_a);
}

void	do_sb_ch(t_stack **stack_b)
{
	if (!*stack_b)
		return ;
	swap(*stack_b);
}

void	do_ss_ch(t_stack **stack_a, t_stack **stack_b)
{
	do_sa_ch(stack_a);
	do_sb_ch(stack_b);
}

int	is_number(char *av)
{
	int	i;

	i = 0;
	if (is_signe(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_digit(av[i]))
		i++;
	if (av[i] && !is_digit(av[i]))
		return (0);
	return (1);
}
