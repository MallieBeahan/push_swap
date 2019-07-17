/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:49:28 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/17 22:30:26 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void first_case(t_stack **stack_a)
{
    int first;
    int second;
    int third;

    first = (*stack_a)->num;
    second = (*stack_a)->next->num;
    third = (*stack_a)->next->next->num;
    if (first > second && third > first)
        sa((*stack_a), 1);
    if (first > second && first > third && second > third)
    {
        sa((*stack_a), 1);
        rra((*stack_a), 1);
    }
    if (first > second && first > third && third > second)
        ra((*stack_a), 1);
    if (second > first && second > third && third > first)
    {
        sa((*stack_a), 1);
        ra((*stack_a), 1);
    }
    if (second > first && second > third && first > third)
        rra((*stack_a), 1);
}

void second_case(t_stack *stack_a, t_stack *stack_b, int size)
{
    int heap;
    int first;
    int second;
    int check;
    t_stack *start;

    heap = find_digit(stack_a, size);
    start = stack_a;
    check = heap;
    while (heap <= check * 5)
    {
        first = check * 10;
        second = first;
        while (stack_a)
        {
            if (first > stack_a->num && stack_a->filled && stack_a->num <= heap)
            {
                second = first;
                first = stack_a->num;
            }
            if (second > stack_a->num && first < stack_a->num && stack_a->filled && stack_a->num <= heap)
                second = stack_a->num;
            stack_a = stack_a->next;
        }
        if (check == 1)
            help_func_less(first, start, size, stack_b);
        else
            help_func_ten(first, second, start, size, stack_b);
        heap = check_digit(start, heap, check);
        stack_a = start;
    }
    push_b_to_a(stack_a, stack_b, size);
}

void help_func_ten(int first, int second, t_stack *stack_a, int size, t_stack *stack_b)
{
    int pos_first;
    int pos_second;
    int count;
    t_stack *start;

    start = stack_a;
    count = 0;
    pos_first = 0;
    pos_second = 0;
    while (stack_a)
    {
        if (stack_a->num == first && stack_a->filled)
            pos_first = count;
        if(stack_a->num == second && stack_a->filled)
            pos_second = count;
        stack_a = stack_a->next;
        count++;
    }
    if (size - pos_first < size - pos_second)
    {
        while(size - 1 - pos_first)
        {
            ra(start, 1);
            pos_first--;
        }
        pb(start, stack_b);
    }
    else
    {
        while (pos_second + 1 < size)
        {
            rra(start, 1);
            pos_second++;
        }
        pb(start, stack_b);
        while (pos_first + 1 < size)
        {
            rra(start, 1);
            pos_first++;
        }
        pb(start, stack_b);
        sb(stack_b, 1);
    }
}

void help_func_less(int first, t_stack *stack_a, int size, t_stack *stack_b)
{
    int pos_first;
    int count;
    t_stack *start;

    start = stack_a;
    count = 0;
    pos_first = 0;
    while (stack_a)
    {
        if (stack_a->num == first && stack_a->filled)
            pos_first = count;
        stack_a = stack_a->next;
        count++;
    }
    if (pos_first <= size - pos_first)
    {
        while (pos_first + 1)
        {
            ra(start, 1);
            pos_first--;
        }
        pb(start, stack_b);
        ra(start, 0);
    }
    else
    {
        while (size > pos_first + 1)
        {
            rra(start, 1);
            pos_first++;
        }
        pb(start, stack_b);
        rra(start, 0);
    }
}