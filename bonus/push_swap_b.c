/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:58:18 by yismaail          #+#    #+#             */
/*   Updated: 2023/02/06 20:25:59 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	iss_sorted(t_stack *stack)
{
	while (stack->next != '\0')
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

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

int	is_signe(char c)
{
	return (c == '+' || c == '-');
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	main(int ac, char **av)
{
	char	*big_str;
	int		stack_size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac <= 1)
		return (0);
	input_is_valide(av);
	big_str = ft_join_all_args(av);
	if (check_duplicate(big_str) == 0)
		ft_exit();
	stack_b = NULL;
	stack_a = fill_stack_by_value(big_str);
	ft_checker(&stack_a, &stack_b);
	stack_size = get_stack_size(stack_b);
	if (stack_size == 0 && iss_sorted(stack_a) == 1)
		write(1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	system("leaks checker");
	return (0);
}
