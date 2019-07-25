/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:31:12 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/25 13:14:12 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(t_list *lst)
{
    int pivot;
    int i;
    t_block *block;
    t_block *node;

    block = (t_block *)malloc(sizeof(block));
    block->ops = 0;
    block->next = NULL;
    while (lst->size_a > 3)
    {
        i = 0;
        pivot = find_pivot((const int *)lst->stack_a, lst->size_a);
        while (i <= lst->size_a)
        {
            if (lst->stack_a[lst->size_a - 1] >= pivot)
            {
                pb(lst, 1);
                block->ops += 1;
            }
            else
            {
                ra(lst, 1);
                i++;
            }
        }
        node = (t_block *)malloc(sizeof(node));
        ft_lstadd(&block, node);
    }
}