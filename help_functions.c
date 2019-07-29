/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:49:32 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/26 19:37:24 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize(t_list *lst, int ac)
{
	lst->stack_a = (int *)malloc(sizeof(int) * ac - 1);
	lst->stack_b = (int *)ft_memalloc(sizeof(int) * ac - 1);
	lst->size_a = ac - 1;
	lst->size_b = 0;
}

t_list	*fill_lst(t_list *lst, int ac, char **av)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (i < ac - 1)
    {
        lst->stack_a[i] = ft_atoi(av[j]);
        i++;
        j++;
    }
    return (lst);
}

void	rrr(t_list *lst)
{
    if (lst)
    {
        rra(lst, 0);
        rrb(lst, 0);
        write(1, "rrr\n", 4);
    }
}

int	*copyarr(const int *arr, int k)
{
	int i;
	int *copy;

	i = 0;
	copy = (int *)malloc(sizeof(int) * k + 1);
	while (i < k)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}


int		find_pivot(const int *arr, int size)
{
	int *new_arr;
    int pivot;

    pivot = 0;
    new_arr = copyarr(arr, size);
    sort_arr(new_arr, size);
    if (size % 2 == 0)
        pivot = ((new_arr[size / 2] + new_arr[(size / 2) - 1]) / 2);
    else
        pivot = new_arr[size / 2];
    free(new_arr);
    return (pivot);
}