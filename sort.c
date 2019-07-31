/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:31:12 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/31 21:35:07 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void clear_stack_more(t_list *lst, t_block *a_block, t_block *b_block)
{
    int pivot;
    int count;
    int i;
    t_block *node;

    i = 0;
    pivot = find_pivot((const int *)lst->stack_a, lst->size_a - a_block->bl_size);
    count = find_count((const int *)lst->stack_a, lst->size_a - a_block->bl_size, pivot);
    if (lst->bl_b_count == 0)
        b_block = (t_block *)ft_memalloc(sizeof(t_block));
    else 
    {
        node =(t_block *)ft_memalloc(sizeof(t_block));
        ft_lstadd(&b_block, node);
    }
    while (count)
    {
        if (lst->stack_a[0] <= pivot)
        {
            pb(lst, 1);
            count--;
        }
        else
        {
            ra(lst, 1);
            i++;
        }
    }
    restore_stack(lst, i);
    if (lst->size_a - a_block->bl_size <= 3)
        sort_stack_a(lst, a_block, lst->size_a - a_block->bl_size);
}

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

void sort_stack_a(t_list *lst, t_block *a_block, int size)
{
    if (size > 1 && lst->stack_a[0] > lst->stack_a[1])
        sa(lst, 1);
    if (size > 2 && lst->stack_a[1] > lst->stack_a[2])
    {
        ra(lst, 1);
        sa(lst, 1);
        rra(lst, 1);
    }
    if (size > 1 && lst->stack_a[0] > lst->stack_a[1])
        sa(lst, 1);
    lst->bl_a_count = 1;
    a_block->bl_size += size;
}

void clear_stack_b(t_list *lst, t_block *a_block, t_block *b_block)
{
    t_block *tmp_b;
    int flag;

    flag = 1;
    tmp_b = b_block;
    while(b_block->bl_size)
    {
        pa(lst, 1);
        b_block->bl_size--;
    }
    if (lst->size_a - a_block->bl_size <= 3)
    {
        sort_stack_a(lst, a_block, lst->size_a - a_block->bl_size);
        flag = 0;
    }
    lst->bl_b_count--;
    tmp_b = b_block;
    if (b_block->next)
        b_block = b_block->next;
    free(tmp_b);
    if (flag)
        clear_stack_more(lst, a_block, b_block);
}

void clear_stack_a(t_list *lst, t_block *a_block, t_block *b_block)
{
    int pivot;
    int count;

    pivot = 0;
    count = 0;
    pivot = find_pivot((const int *)lst->stack_a + a_block->bl_size, lst->size_a - a_block->bl_size);
    count = find_count(lst->stack_a, lst->size_a - a_block->bl_size, pivot);
    while (count)
    {
        if (lst->stack_a[0] <= pivot)
        {
            pb(lst, 1);
            count--;
        }
        else
            ra(lst, 1);
    }
    if (lst->bl_b_count == 0)
        b_block->bl_size = lst->size_b;
    else
        b_block->bl_size = lst->size_b - dont_touch(b_block);
    lst->bl_b_count++;
}

void sort_three_elem(t_list *lst, t_block blocks)
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
    blocks.sort_in_a = lst->size_a;
}

void sort(t_list *lst)
{
    t_block blocks;
    int check;

    ft_bzero(&blocks, sizeof(blocks));
    check = lst->size_a;
    if (lst->size_a <= 3)
        sort_three_elem(lst, blocks);
    else
    {
        while (lst->size_a > 3)
        {
            if (!b_block)
            {
                a_block = (t_block *)ft_memalloc(sizeof(t_block));
                b_block = (t_block *)ft_memalloc(sizeof(t_block));
                a_block->next = NULL;
                b_block->next = NULL;
            }
            else
            {
                node = (t_block *)ft_memalloc(sizeof(t_block));
                ft_lstadd(&b_block, node);
            }
            clear_stack_a(lst, a_block, b_block);
        }
        sort_three_elem(lst, a_block);
        lst->bl_a_count++;
        a_block->bl_size = lst->size_a;
        while(check > a_block->bl_size)
        {
            clear_stack_b(lst, a_block, b_block);
            if (lst->bl_b_count == 0)
                b_block->bl_size = lst->size_b;
            else
                b_block->bl_size = lst->size_b - dont_touch(b_block);
            if (b_block->next)
                b_block = b_block->next;
        }
    }
}