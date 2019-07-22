/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:49:28 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/22 19:11:08 by mbeahan          ###   ########.fr       */
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

void second_case(t_stack *stack_a, int size)
{
    int heap;
    int first;
    int second;
    int check;
    t_stack *start;
    t_stack *stack_b;

    stack_b = NULL;
    heap = find_digit(stack_a, size);
    start = stack_a;
    check = heap;
    while (heap < check * 5)
    {
        first = check * 10;
        second = first;
        while (stack_a)
        {
            if (first > stack_a->num && stack_a->num <= heap)
            {
                second = first;
                first = stack_a->num;
            }
            if (second > stack_a->num && first < stack_a->num && stack_a->num <= heap)
                second = stack_a->num;
            stack_a = stack_a->next;
        }
        if (check == 1)
            stack_b = help_func_less(first, start, stack_b, size);
        else
            stack_b = help_func_ten(first, second, start, stack_b, size); // если он кидает в стек б второе число по величине обработать и обработать чтобы постоянно не искал первое и второе
        heap = check_digit(start, heap, check);
        stack_a = start;
        if (check == 1)
            size--;
        else
            size -= 2;
    }
    size = lst_size(stack_b);
    while(stack_b && size >= 1)
    {
        stack_a = pa(stack_a, stack_b);
        size--;
    }
    rra(stack_a, 1);
    stack_b = NULL;
}

t_stack *help_func_ten(int first, int second, t_stack *stack_a, t_stack *stack_b, int size)
{
    int pos_first;
    int pos_second;
    int count;
    t_stack *start;

    start = stack_a;
    count = 1;
    pos_first = 0;
    pos_second = 0;
    while (stack_a->next)
    {
        if (stack_a->num == first)
            pos_first = count;
        if(stack_a->num == second)
            pos_second = count;
        stack_a = stack_a->next;
        count++;
    }
    if (what_to_do(pos_first, pos_second, size) == 0)
    {
        stack_b = push_second_digit(pos_first, start, stack_b, size);
        pos_second = find_pos(start, second);
        stack_b = push_second_digit(pos_second, start, stack_b, size);
    }
    else
    {
        stack_b = push_second_digit(pos_second, start, stack_b, size);
        pos_first = find_pos(start, first);
        stack_b = push_second_digit(pos_first, start, stack_b, size);
        sb(stack_b, 1);
    }
    return (stack_b);
}

t_stack *help_func_less(int first, t_stack *stack_a, t_stack *stack_b, int size)
{
    int pos_first;
    int count;
    t_stack *start;

    start = stack_a;
    count = 1;
    pos_first = 0;
    while (stack_a)
    {
        if (stack_a->num == first)
            pos_first = count;
        stack_a = stack_a->next;
        count++;
    }
    if (size / 2 >= pos_first)
    {
        while (pos_first)
        {
            ra(start, 1);
            pos_first--;
        }
        stack_b = pb(start, stack_b);
    }
    else
    {
        while (size - pos_first)
        {
            rra(start, 1);
            pos_first++;
        }
        stack_b = pb(start, stack_b);
    }
    return (stack_b);
}