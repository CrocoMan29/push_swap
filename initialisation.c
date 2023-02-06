/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:58:19 by yismaail          #+#    #+#             */
/*   Updated: 2023/02/06 20:17:04 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack_by_value(char *str)
{
	t_stack		*stack_a;
	int			i;
	char		**sub_str;
	long int	nb;

	sub_str = ft_split(str, ' ');
	i = 0;
	stack_a = NULL;
	while (sub_str[i])
	{
		nb = ft_atoi2(sub_str[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 0)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	ft_free_tab(sub_str);
	return (stack_a);
}

void	assigne_index(t_stack *stack, int size_stack)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--size_stack > 0)
	{
		ptr = stack;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack;
			}
			else
				ptr = ptr->next;
		}
		if (highest != 0)
			highest->index = size_stack;
	}
}
