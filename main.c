/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:47:11 by yismaail          #+#    #+#             */
/*   Updated: 2023/01/29 16:00:27 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
	char *big_str;
	int	stack_size;
	t_stack *stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	if (ft_strlen(av[1]) == 0)
		exit(12);
	//! leaaaaaaaaaks in input_is_valide
	input_is_valide(av);
	big_str = ft_join_all_args(av);
	if (check_duplicate(big_str) == 0)
	{
		write(1, "ERROR", 5);
		exit(22);
	}
	stack_b = NULL;
	stack_a = fill_stack_by_value(big_str);
	stack_size = get_stack_size(stack_a);
	//printf ("---->%s", big_str);
	//system("leaks push_swap");
}