/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:31:12 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/29 21:33:10 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_elem(t_list *lst)
{
    int first;
    int second;
    int third;

    first = 0;
    second = 0;
    third = 0;
    if (lst->size_a == 1)
        return ;
    if (lst->size_a == 2)
    {
        if (lst->stack_a[1] > lst->stack_a[0])
            sa(lst, 1);
    }
    if (lst->size_a == 3)
    {
        first = lst->stack_a[2];
        second = lst->stack_a[1];
        third = lst->stack_a[0];
        if (third > second && third > first)
            return ;
        if (first > second && first < third)
            sa(lst, 1);
        if (first > second && first > third && second > third)
        {
            sa(lst, 1);
            rra(lst, 1);
        }
        if (first > second && first > third && third > second)
            ra(lst, 1);
        if (first < second && first < third)
        {
            sa(lst, 1);
            ra(lst, 1);
        }
        if (first > third && first < second)
            rra(lst, 1);
    }
}

void push_back(t_list *lst, t_block *a_block, t_block *b_block)
{
    int i;
    int pivot;
    t_block *node;
    t_block *tmp;

    i = 0;
    tmp = b_block;
    while(b_block->next && b_block->bl_size)
    {
        // b_block->bl_size <= 3 ? push_and_sort(lst) : 0; // пушит три или меньше элемента в стек А и сортирует их там free(b_block) b_block = b-block_>next
        pivot = find_pivot((const int *)lst->stack_b, b_block->bl_size);
        while (i <= b_block->bl_size)
        {
            if(lst->stack_b[lst->size_b - 1] > pivot)
            {
                pa(lst, 1);
                b_block->bl_size--;
                a_block->bl_size++;
            }
            else
            {
                rb(lst, 1);
                i++;
            }
            node = (t_block *)malloc(sizeof(node));
            ft_lstadd(&a_block, node);
            while (i < 0)
            {
                rrb(lst, 1);
                i++;
            }
        }
    }
}

void sort(t_list *lst)
{
    int pivot;
    int i;
    t_block *a_block;
    t_block *b_block;
    t_block *node;

    if (lst->size_a > 3)
    {
        a_block = (t_block *)malloc(sizeof(a_block));
        b_block = (t_block *)malloc(sizeof(b_block));
    }
    init_blocks(a_block, lst);
    init_blocks(b_block, lst);
    while (lst->size_a > 3)
    {
        i = 0;
        pivot = find_pivot((const int *)lst->stack_a, lst->size_a);
        while (i <= lst->size_a)
        {
            if (lst->stack_a[lst->size_a - 1] < pivot)
            {
                pb(lst, 1);
                b_block->bl_size++;
            }
            else
            {
                ra(lst, 1);
                i++;
            }
        }
        node = (t_block *)ft_memalloc(sizeof(node));
        ft_lstadd(&b_block, node);
    }
    if (b_block)
        b_block = needed_block(b_block);
    sort_three_elem(lst);
    push_back(lst, a_block, b_block);
}