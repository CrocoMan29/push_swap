/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:58:27 by yismaail          #+#    #+#             */
/*   Updated: 2023/01/28 23:29:36 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arg_is_zero(char *av)
{
	int i;

	i = 0;
	if (is_signe(av[i]) == 1)
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

void	input_is_valide(char **av)
{
	int i;
	int j;
	char **sub_str;
	int nb_zero;

	i = 0;
	nb_zero = 0;

	while (av[++i])
	{
		if (ft_strlen(av[i]) == 0)
		{
			ft_free_tab(sub_str);
			exit(11);
		}
		sub_str = ft_split(av[i], ' ');
		j = -1;
		while (sub_str[++j])
		{
			if (is_number(sub_str[j]) == 0)
			{
				free(sub_str);
				ft_putstr_fd("ERROR", 1);
				exit(1);
			}
			nb_zero += arg_is_zero(sub_str[j]);
		}
		if (nb_zero > 1)
			exit(33);
	}
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

char	*ft_join_all_args(char **av)
{
	int i;
	char *first_join;

	i = 1;
	first_join=NULL;
	while (av[i])
	{
		first_join = ft_strjoin(first_join, " ");
		first_join = ft_strjoin(first_join, av[i]);
		i++;
	}
	return (first_join);
}

int	check_duplicate(char *str)
{
	char **num;
	int i;
	int j;
	
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
	return (1);
}
