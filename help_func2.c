/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:25:24 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/30 23:32:29 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *sort_arr(int *arr, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size - 1)
    {
        j = i;
        while (j < size)
        {
            if (arr[i] > arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        i++;
    }
    return (arr);
}

void	init_blocks(t_block *block, t_list *lst)
{
    if (lst->size_a > 3)
    {
        block->bl_size = 0;
	    block->next = NULL;
    }
    else
        block = NULL;
}

int dont_touch(t_block *block)
{
    int sum;

    sum = 0;
    if (block->next)
    {
        while(block->next)
        {
            sum += block->bl_size;
            block = block->next;
        }
    }
    return (sum);
}

t_block *needed_block(t_block *block)
{
    t_block *tmp;

    tmp = block;
    while(block->next && block->bl_size == 0)
    {
        tmp = block->next;
        free(block);
        block = NULL;
        block = block->next;
    }
    if (block && !block->next && block->bl_size == 0)
    {
        free(tmp);
        tmp = NULL;
    }
    return (tmp);
}