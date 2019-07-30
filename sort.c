/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:31:12 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/30 23:32:37 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_blocks(int *stack, t_block *block, int size)
{
    int pivot;
    int count;


    pivot = find_pivot((const int *)stack + dont_touch(block), size - dont_touch(block));
}

void sort_three_elem(t_list *lst)
{
    int first;
    int second;
    int third;

    if (lst->size_a == 1)
        return ;
    if (lst->size_a == 2)
    {
        if (lst->stack_a[0] > lst->stack_a[1])
            sa(lst, 1);
    }
    if (lst->size_a == 3)
    {
        first = lst->stack_a[0];
        second = lst->stack_a[1];
        third = lst->stack_a[2];
        if (first > second && first < third)
            sa(lst, 1);
        if (first > second && first > third && second > third)
        {
            sa(lst, 1);
            rra(lst, 1);
        }
        if (first > second && first > third && third > second)
            ra(lst, 1);
        if (first < second && first < third && second > third)
        {
            sa(lst, 1);
            ra(lst, 1);
        }
        if (first > third && first < second)
            rra(lst, 1);
    }
}

void sort(t_list *lst)
{
    int pivot;
    int i;
    t_block *a_block;
    t_block *b_block;
    t_block *node;


    if (lst->size_a <= 3)
        sort_three_elem(lst);
    else
    {
        a_block = (t_block *)ft_memalloc(sizeof(t_block));
        b_block = (t_block *)ft_memalloc(sizeof(t_block));
        while (lst->size_a > 3)
            swap_blocks(lst->stack_a, b_block, lst->size_a);
        
    }
}