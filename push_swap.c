/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:15:37 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/22 23:42:11 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *dup_stack(int *stack, int size)
{
    int i;
    int *new_stack;

    i = 0;
    if (stack)
    {
        new_stack = (int *)ft_memalloc(sizeof(int) * size);
        while (i < size)
        {
            new_stack[i] = stack[i];
            i++;
        }
    }
    return (new_stack);
}