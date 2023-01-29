/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:52:15 by yismaail          #+#    #+#             */
/*   Updated: 2023/01/29 15:56:59 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack *new;

	new = malloc(sizeof * new);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_stack *get_tail_of_stack(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*tail;
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_tail_of_stack(*stack);
	tail->next = new;
}

int	get_stack_size(t_stack *stack)
{
	int i;

	i = 0;
	if (!stack)
		return (0);
	while (stack->next != '\0')
	{
		stack = stack->next;
		i++;
	}
	return (i);
}