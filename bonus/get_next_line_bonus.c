/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:25:53 by yismaail          #+#    #+#             */
/*   Updated: 2023/02/06 20:27:16 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_read_str(int fd, char *read_4m_left)
{
	char	*new_str;
	int		bytes_read;

	new_str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	bytes_read = 1;
	while (!ftft_strchr(read_4m_left, '\n') && bytes_read)
	{
		bytes_read = read(fd, new_str, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(new_str);
			free(read_4m_left);
			new_str = NULL;
			read_4m_left = NULL;
			return (NULL);
		}
		new_str[bytes_read] = '\0';
		read_4m_left = ft_strjoin(read_4m_left, new_str);
	}
	free(new_str);
	return (read_4m_left);
}

char	*get_next_line(int fd)
{
	static char	*read_4m_left[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_4m_left[fd] = ft_read_str(fd, read_4m_left[fd]);
	if (!read_4m_left[fd])
		return (NULL);
	line = ft_get_our_line(read_4m_left[fd]);
	read_4m_left[fd] = ft_new_str(read_4m_left[fd]);
	return (line);
}

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

long int	ft_atoi2(char *nbr)
{
	int			i;
	int			signe;
	long int	nb;

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

void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a != NULL && *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b != NULL && *stack_b != NULL)
		free_stack(stack_b);
	write(2, "ERROR\n", 6);
	exit(1);
}
