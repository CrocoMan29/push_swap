/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:43:17 by yismaail          #+#    #+#             */
/*   Updated: 2023/02/05 09:14:48 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rev_rorate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tail;
    t_stack *before_tail;

    tail = get_tail_of_stack(*stack);
    before_tail = get_befor_tail_stack(*stack);
    tmp = *stack;
    *stack = tail;
    (*stack)->next = tmp;
    before_tail->next = NULL;
}

void do_rra(t_stack **stack_a)
{
    rev_rotate(stack_a);
    ft_putstr("rra\n");
}

void do_rrb(t_stack **stack_b)
{
    rev_rotate(stack_b);
    ft_putstr("rrb\n");
}

void do_rrr(t_stack **stack_a, t_stack **stack_b)
{
    rev_rotate(stack_a);
    rev_rotate(stack_b);
    ft_putstr("rrr\n");
}