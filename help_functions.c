/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 16:08:50 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/17 21:42:39 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd(t_stack **stack, t_stack *new, int num, int filled)
{
	if (stack && new)
	{
        new->next = *stack;
        new->num = num;
        if (filled)
            new->filled = 1;
        else
            new->filled = 0;
		*stack = new;
            
	}
}

int     lst_size(t_stack *stack)
{
    int count;

    count = 0;
    if (stack)
    {
        while (stack)
        {
            stack= stack->next;
            count++;
        }
    }
    return (count);
}

void print_stack(t_stack *stack)
{
    while (stack->next)
    {
        printf("%d\n", stack->num);
        stack = stack->next;
    }
    printf("%d", stack->num);
}

t_stack *create_b(int size)
{
    t_stack *b;
    t_stack *node;
    int i;

    i = 0;
    b = ft_memalloc(sizeof(b));
    while (i < size - 1)
    {
        node = ft_memalloc(sizeof(node));
        ft_lstadd(&b, node, 0, 0);
        i++;
    }
    return (b);
}

int find_digit(t_stack *lst,int size)
{
    int digit;
    int sum;

    sum = 0;
    digit = 0;
    while (lst)
    {
        sum += lst->num;
        lst = lst->next;
    }
    digit = ((sum / size) / 2) * 0.8;
    if (!digit)
        return (1);
    return (digit);
}

int check_digit(t_stack *stack_a, int digit, int check)
{
    while(stack_a)
    {
        if (digit >= stack_a->num && stack_a->filled)
            return (digit);
        stack_a = stack_a->next;
    }
    return (digit + check);
}

void push_b_to_a(t_stack *a, t_stack *b, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        pa(a, b);
        i++;
    }
}