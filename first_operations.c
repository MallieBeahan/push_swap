/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:52:06 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/17 22:24:51 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, int print)
{
    int first;
    int second;

    if (stack_a->next)
    {
        first = stack_a->num;
        second = stack_a->next->num;
        stack_a->num = second;
        stack_a->next->num = first;
        if (print)
            write(1, "sa\n", 3);
    }
}

void	sb(t_stack *stack_b, int print)
{
    int first;
    int second;

    if (stack_b->next)
    {
        first = stack_b->num;
        second = stack_b->next->num;
        stack_b->num = second;
        stack_b->next->num = first;
        if (print)
            write(1, "sb\n", 3);
    }
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a && stack_b)
    {
        sa(stack_a, 0);
        sb(stack_b, 0);
        write(1, "ss\n", 3);
    }
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
    while(!stack_b->filled && stack_b->next)
        stack_b = stack_b->next;
    while(stack_b->next)
        stack_a = stack_a->next;
	if(stack_a && stack_b && stack_b->num && stack_b->filled)
	{
        rra(stack_a, 0);
        stack_a->num = stack_b->num;
        stack_b->num = 0;
        stack_b->filled = 0;
        stack_a->filled = 1;
        write(1, "pa\n", 3);
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
    while(!stack_a->filled && stack_a->next)
        stack_a = stack_a->next;
    while(stack_a->next)
        stack_a = stack_a->next;
	if(stack_a && stack_b && stack_a->num && stack_a->filled)
	{
        rrb(stack_b, 0);
        stack_b->num = stack_a->num;
        stack_a->num = 0;
        stack_a->filled = 0;
        stack_b->filled = 1;
        write(1, "pb\n", 3);
	}
}