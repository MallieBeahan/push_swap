/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:52:06 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/18 20:15:05 by mbeahan          ###   ########.fr       */
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

t_stack	*pa(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp;
    t_stack *node;
    int size;

    if (stack_b)
        size = lst_size(stack_b);
    while (stack_b->next && stack_b->next->next)
        stack_b = stack_b->next;
    tmp = stack_b;
    if (size > 1)
        stack_b = stack_b->next;
    if(stack_a && stack_b && stack_b->num)
	{
        node = ft_memalloc(sizeof(node));
        ft_lstadd(&stack_a, node, stack_b->num);
        free(stack_b);
        tmp->next = NULL;
        write(1, "pa\n", 3);
	}
    if (!stack_a)
    {
        stack_a = ft_memalloc(sizeof(stack_a));
        stack_a->num = stack_b->num;
        stack_a->next = NULL;
        free(stack_b);
        tmp->next = NULL;
        write(1, "pa\n", 3);
    }
    return (stack_a);
}

t_stack	*pb(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp;
    t_stack *node;
    int size;

    if (stack_a)
        size = lst_size(stack_a);
    while (stack_a->next && stack_a->next->next)
        stack_a = stack_a->next;
    tmp = stack_a;
    if (size > 1)
        stack_a = stack_a->next;
    if(stack_a && stack_b && stack_a->num)
	{
        node = ft_memalloc(sizeof(node));
        ft_lstadd(&stack_b, node, stack_a->num);
        free(stack_a);
        tmp->next = NULL;
        write(1, "pb\n", 3);
	}
    if (!stack_b)
    {
        stack_b = ft_memalloc(sizeof(stack_b));
        stack_b->num = stack_a->num;
        stack_b->next = NULL;
        free(stack_a);
        tmp->next = NULL;
        write(1, "pb\n", 3);
    }
    return (stack_b);
}