/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:25:24 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/31 22:36:23 by mbeahan          ###   ########.fr       */
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

int dont_touch(t_block blocks)
{
    int sum;
    int i;

    i = 0;
    sum = 0;
    while(i < blocks.i + 1)
    {
        sum += blocks.blocks[i];
        i++;
    }
    return (sum);
}