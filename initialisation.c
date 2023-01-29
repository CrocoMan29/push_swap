/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:58:19 by yismaail          #+#    #+#             */
/*   Updated: 2023/01/28 23:23:45 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack_by_value(char *str)
{
	t_stack *stack_a;
	int i;
	char **sub_str;
	long int nb;

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
	return (stack_a);
}