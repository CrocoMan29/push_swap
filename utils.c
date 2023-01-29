/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:02:10 by yismaail          #+#    #+#             */
/*   Updated: 2023/01/28 23:25:13 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int ft_atoi2(char *nbr)
{
	int i;
	int signe;
	long int nb;

	i = 0;
	nb = 0;
	signe = 1;
	if (nbr[i] == '+')
		i++;
	else if (nbr[i] == '-')
	{
		signe *= -1;
		i++;
	}
	while (is_digit(nbr[i]))
	{
		nb = nb * 10 + nbr[i] - '0';
		i++;
	}
	return (signe * nb);
}

void	ft_free_tab(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	free_stack(t_stack **stack)
{
	t_stack *tmp;
	
	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL && *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL && *stack_b != NULL)
		free_stack(stack_b);
	write(2, "ERROR\n", 6);
	exit(1);
}