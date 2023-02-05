/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 06:43:23 by yismaail          #+#    #+#             */
/*   Updated: 2023/02/05 09:15:42 by yismaail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_stack **src, t_stack **dst)
{
    t_stack *tmp;

    if (*src == NULL)
        return ;
    tmp = (*src)->next;
    (*src)->next = *dst;
    *dst = *src;
    *src = tmp;
}

void do_pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
    ft_putstr("pa\n");
}

void do_pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    ft_putstr("pb\n");
}