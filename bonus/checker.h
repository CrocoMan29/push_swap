/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:18:11 by yismaail          #+#    #+#             */
/*   Updated: 2023/02/06 20:30:52 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//*checker
char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *read_4m_left);
char	*ft_get_our_line(char *read_4m_left);
char	*ft_new_str(char *read_4m_left);
void	ft_checker(t_stack **a, t_stack **b);
void	ft_action(t_stack **a, t_stack **b, char *line);
void	ft_error(void);
char	*ftft_strchr(char *str, int symbole);
void	ft_ft_exit(char **str);
void	ft_exit(void);

//*instruction
void	do_sa_ch(t_stack **stack_a);
void	do_sb_ch(t_stack **stack_b);
void	do_ss_ch(t_stack **stack_a, t_stack **stack_b);
void	do_ra_ch(t_stack **stack_a);
void	do_rb_ch(t_stack **stack_b);
void	do_rr_ch(t_stack **stack_a, t_stack **stack_b);
void	do_rra_ch(t_stack **stack_a);
void	do_rrb_ch(t_stack **stack_b);
void	do_rrr_ch(t_stack **stack_a, t_stack **stack_b);
void	do_pa_ch(t_stack **stack_a, t_stack **stack_b);
void	do_pb_ch(t_stack **stack_a, t_stack **stack_b);

#endif