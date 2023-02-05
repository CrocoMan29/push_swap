/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:43:12 by yismaail          #+#    #+#             */
/*   Updated: 2023/02/05 09:11:04 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tail;

    tmp = *stack;
    *stack = (*stack)->next;
    tail = get_tail_of_stack(*stack);
    tmp->next = NULL;
    tail->next = tmp;
}

void do_ra(t_stack **stack_a)
{
    rotate(stack_a);
    ft_putstr("ra\n");
}

void do_rb(t_stack **stack_b)
{
    rotate(stack_b);
    ft_putstr("rb\n");
}

void do_rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_putstr("rr\n");
}