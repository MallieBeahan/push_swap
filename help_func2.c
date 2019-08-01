/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:25:24 by mbeahan           #+#    #+#             */
/*   Updated: 2019/08/01 12:38:17 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_list *lst)
{
    int i;

    i = 0;
    printf("Your stack is:\n");
    while (i < lst->size_a)
    {
        printf("%d\n", lst->stack_a[i]);
        i++;
    }
}

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

int dont_touch(t_block blocks, int size)
{
    int sum;
    int i;

    i = 0;
    sum = 0;
    while(i < size + 1)
    {
        sum += blocks.blocks[i];
        i++;
    }
    return (sum);
}