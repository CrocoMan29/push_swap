/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:43:17 by yismaail          #+#    #+#             */
/*   Updated: 2023/02/06 20:24:02 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_tail_of_stack(*stack);
	before_tail = get_befor_tail_stack(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	do_rra_ch(t_stack **stack_a)
{
	if (!*stack_a)
		return ;
	rev_rotate(stack_a);
}

void	do_rrb_ch(t_stack **stack_b)
{
	if (!*stack_b)
		return ;
	rev_rotate(stack_b);
}

void	do_rrr_ch(t_stack **stack_a, t_stack **stack_b)
{
	do_rra_ch(stack_a);
	do_rrb_ch(stack_b);
}

int	check_duplicate(char *str)
{
	char	**num;
	int		i;
	int		j;

	i = 0;
	num = ft_split(str, ' ');
	while (num[i])
	{
		j = 0;
		while (num[j])
		{
			if (i != j && nb_cmp(num[i], num[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	ft_free_tab(num);
	return (1);
}
