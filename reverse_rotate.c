#include "push_swap.h"

static void rev_rorate(t_stack *stack)
{
    t_stack *tmp;
    t_stack *tail;
    t_stack *before_tail;

    tail = get_tail_of_stack(stack);
    before_tail = get_befor_tail_stack(stack);
    tmp = *stack;
    *stack = tail;
    (*stack)->next = tmp;
    before_tail->next = NULL;
}

void rra(t_stack **stack_a);
{
    rev_rotate(*stack_a);
    ft_putstr("rra\n");
}

void rrb(t_stack **stack_b)
{
    rev_rotate(*stack_b);
    ft_putstr("rrb\n");
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    rev_rotate(*stack_a);
    rev_rotate(*stack_b);
    ft_putstr("rrr\n");
}