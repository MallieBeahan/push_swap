/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 16:08:50 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/22 21:15:33 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_lstnew(t_stack **stack, int num)
{
	t_stack *new_list;

	new_list = (t_stack *)ft_memalloc(sizeof(t_stack));
	if (new_list == NULL)
		return (NULL);
	else
		new_list->num = num;
	new_list->next = NULL;
    *stack = new_list;
    return ((*stack));
}

void	ft_lstadd(t_stack **stack, t_stack *new, int num)
{
	if (stack && new)
	{
        new->next = *stack;
        new->num = num;
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
        if (digit >= stack_a->num)
            return (digit);
        stack_a = stack_a->next;
    }
    return (digit + check);
}

int what_to_do(int pos_first, int pos_second, int size)
{
    int first;
    int second;

    if (pos_first >= size / 2)
        first = size - pos_first;
    else
        first = pos_first;
    if (pos_second >= size / 2)
        second = size - pos_second;
    else
        second = pos_second;
    if (first >= second)
        return (1);
    return (0);
}

t_stack *push_second_digit(int pos, t_stack *stack_a, t_stack *stack_b, int size)
{
    if (size / 2 >= pos)
    {
        while (pos)
        {
            ra(stack_a, 1);
            pos--;
        }
        stack_b = pb(stack_a, stack_b);
    }
    else
    {
        while (size - pos)
        {
            rra(stack_a, 1);
            pos++;
        }
        stack_b = pb(stack_a, stack_b);
    }
    return (stack_b);
}

int find_pos(t_stack *stack, int digit)
{
    int pos;

    pos = 1;
    while(stack->next && stack->num != digit)
    {
        stack = stack->next;
        pos++;
    }
    return (pos);
}