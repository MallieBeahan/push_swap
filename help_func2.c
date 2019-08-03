/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:25:24 by mbeahan           #+#    #+#             */
/*   Updated: 2019/08/03 23:01:26 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_count(const int *stack, int size, int pivot)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while(i < size)
    {
        if(stack[i] <= pivot)
            count++;
        i++;
    }
    return (count);
}

void restore_stack(t_list *lst, int count)
{
    while (count)
    {
        rra(lst, 1);
        count--;
    }
}

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

void    free_all(t_block blocks, t_list *lst)
{
    if (blocks.blocks)
    {
        free(blocks.blocks);
        blocks.blocks = NULL;
    }
    if (lst->stack_a)
    {
        free(lst->stack_a);
        lst->stack_a = NULL;
    }
    if (lst->stack_b)
    {
        free(lst->stack_b);
        lst->stack_b = NULL;
    }
    if (lst)
    {
        free(lst);
        lst = NULL;
    }
}

int	sorted(int *stack, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}