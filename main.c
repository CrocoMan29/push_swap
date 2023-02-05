/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassir <yassir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:47:11 by yismaail          #+#    #+#             */
/*   Updated: 2023/02/04 18:33:12 by yassir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack)
{
	while (stack->next != '\0')
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static	void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		sort_of_3(stack_a)
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int main (int ac, char **av)
{
	char *big_str;
	int	stack_size;
	t_stack *stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	//! leaaaaaaaaaks in input_is_valide
	input_is_valide(av);
	big_str = ft_join_all_args(av);
	if (check_duplicate(big_str) == 0)
	{
		write(2, "ERROR\n", 6);
		exit(22);
	}
	stack_b = NULL;
	stack_a = fill_stack_by_value(big_str);
	stack_size = get_stack_size(stack_a);
	assigne_index(&stack_a, stack_size);
	//printf ("---->%s", big_str);
	//system("leaks push_swap");
}
