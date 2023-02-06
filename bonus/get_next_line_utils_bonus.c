/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:19:54 by yismaail          #+#    #+#             */
/*   Updated: 2023/02/06 20:26:27 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_signe(av[i]) == 1)
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

char	*ft_get_our_line(char *read_4m_left)
{
	int		i;
	char	*new_str;

	i = 0;
	if (!read_4m_left[i])
		return (NULL);
	while (read_4m_left[i] && read_4m_left[i] != '\n')
		i++;
	new_str = malloc((i + 2) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (read_4m_left[i] && read_4m_left[i] != '\n')
	{
		new_str[i] = read_4m_left[i];
		i++;
	}
	if (read_4m_left[i] == '\n')
	{
		new_str[i] = read_4m_left[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_new_str(char *read_4m_left)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	while (read_4m_left[i] && read_4m_left[i] != '\n')
		i++;
	if (!read_4m_left[i])
	{
		free(read_4m_left);
		return (NULL);
	}
	new_line = malloc((ft_strlen(read_4m_left) - i + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i++;
	j = 0;
	while (read_4m_left[i])
		new_line[j++] = read_4m_left[i++];
	new_line[j] = '\0';
	free(read_4m_left);
	return (new_line);
}

void	input_is_valide(char **av)
{
	int		i;
	int		j;
	char	**sub_str;
	int		nb_zero;

	i = 0;
	nb_zero = 0;
	while (av[++i])
	{
		if (ft_isempty(av[i]) == 1)
			ft_exit();
		sub_str = ft_split(av[i], ' ');
		j = -1;
		while (sub_str[++j])
		{
			if (is_number(sub_str[j]) == 0)
				ft_ft_exit(sub_str);
			nb_zero += arg_is_zero(sub_str[j]);
		}
		if (nb_zero > 1)
			ft_exit();
		ft_free_tab(sub_str);
	}
}
