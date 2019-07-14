/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 16:08:50 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/14 21:44:34 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd(t_stack **stack, t_stack *new, int num)
{
	if (stack && new)
	{
        new->next = *stack;
        new->num = num;
		*stack = new;
	}
}

void print_stack(t_stack *stack)
{
    while (stack->next)
    {
        printf("%d ", stack->num);
        stack = stack->next;
    }
    printf("%d", stack->num);
}