/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:52:49 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/14 21:46:06 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack *stack_a, int print)
{
    int tmp;
    t_stack *start;
    
    if (stack_a && stack_a->next)
    {
        start = stack_a;
        while (stack_a->next)
        {
            stack_a = stack_a->next;
            tmp = stack_a->num;
            stack_a->num = start->num;
            start->num = tmp;
        }
        if (print)
            write(1, "rra\n", 3);
    }
}

void rrb(t_stack *stack_b, int print)
{
    int tmp;
    t_stack *start;
    
    if (stack_b && stack_b->next)
    {
        start = stack_b;
        while (stack_b->next)
        {
            stack_b = stack_b->next;
            tmp = stack_b->num;
            stack_b->num = start->num;
            start->num = tmp;
        }
        if (print)
            write(1, "rrb\n", 3);
    }
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a && stack_b)
    {
        rra(stack_a, 0);
        rrb(stack_b, 0);
        write(1, "rrr\n", 3);
    }
}

void ra(t_stack *stack_a, int print)
{
    int first;

    if (stack_a && stack_a->next)
    {
        first = stack_a->num;
        while(stack_a->next->next)
        {
            stack_a->num = stack_a->next->num;
            stack_a = stack_a->next;
        }
        stack_a->num = stack_a->next->num;
        stack_a = stack_a->next;
        stack_a->num = first;
        if (print)
            write(1, "ra\n", 3);
    }
}

void rb(t_stack *stack_b, int print)
{
    int first;

    if (stack_b && stack_b->next)
    {
        first = stack_b->num;
        while(stack_b->next->next)
        {
            stack_b->num = stack_b->next->num;
            stack_b = stack_b->next;
        }
        stack_b->num = stack_b->next->num;
        stack_b = stack_b->next;
        stack_b->num = first;
        if (print)
            write(1, "rb\n", 3);
    }
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a && stack_b)
    {
        ra(stack_a, 0);
        rb(stack_a, 0);
        write(1, "rr\n", 3);
    }
}