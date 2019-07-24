/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:31:12 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/24 21:50:28 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(t_list *lst)
{
    int pivot;
    int i;

    i = 0;
    while (lst->size_a > 3)
    {
        pivot = find_pivot((const int *)lst->stack_a, lst->size_a);
        while (i < lst->size_a)
        {
            if (lst->stack_a[lst->size_a - 1] >= pivot)
                pb(lst, 1);
            else
                ra(lst, 1);
        }
    }
    printf("Your stack A\n");
    i = 0;
    while (i < lst->size_a)
    {
        printf("%d", lst->stack_a[i]);
        i++; 
    }
    printf("\nYour stack B\n");
    i = 0;
    while (i < lst->size_b)
    {
        printf("%d", lst->stack_b[i]);
        i++; 
    }
}