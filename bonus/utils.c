/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:09:19 by yismaail          #+#    #+#             */
/*   Updated: 2023/02/06 20:20:57 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_error(void)
{
	write (2, "ERROR\n", 6);
	exit(1);
}

int	ft_strcmp(char *str, char *src)
{
	int	i;

	i = 0;
	while (str[i] && src[i] && str[i] == src[i])
		i++;
	if (str[i] != src[i])
		return (str[i] - src[i]);
	return (0);
}

void	ft_action(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		do_sa_ch(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		do_sb_ch(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		do_ss_ch(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		do_ra_ch(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		do_rb_ch(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		do_rr_ch(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		do_rra_ch(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		do_rrb_ch(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		do_rrr_ch(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		do_pa_ch(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		do_pb_ch(a, b);
	else
		ft_error();
}

void	ft_checker(t_stack **a, t_stack **b)
{
	char	*res;

	res = NULL;
	while (1)
	{
		res = get_next_line(0);
		if (res == NULL)
			break ;
		ft_action(a, b, res);
		free(res);
	}
}

void	ft_free_tab(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}
