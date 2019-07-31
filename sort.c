/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:31:12 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/31 22:38:54 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void clear_stack_more(t_list *lst, t_block blocks)
{
    int pivot;
    int count;
    int i;
    t_block *node;

    i = 0;
    pivot = find_pivot((const int *)lst->stack_a, lst->size_a - lst->sort_in_a);
    count = find_count((const int *)lst->stack_a, lst->size_a - lst->sort_in_a, pivot);
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
    if (lst->size_a - lst->sort_in_a <= 3)
        sort_stack_a(lst, blocks, lst->size_a - lst->sort_in_a);
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

void sort_stack_a(t_list *lst, t_block blocks, int size)
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
    lst->sort_in_a += size;
}

void clear_stack_b(t_list *lst, t_block blocks)
{
    int flag;

    flag = 1;
    while (blocks.i > 0 && blocks.blocks[blocks.i] == 0)
        blocks.i--;
    if (blocks.blocks[blocks.i] == 0)
        blocks.blocks[blocks.i] = lst->size_b;
    while(blocks.blocks[blocks.i])
    {
        pa(lst, 1);
        blocks.blocks[blocks.i]--;
    }
    if (lst->size_a - lst->sort_in_a <= 3)
    {
        sort_stack_a(lst, blocks, lst->size_a - lst->sort_in_a);
        flag = 0;
    }
    if(blocks.i != 0)
        blocks.i--;
    if (flag)
        clear_stack_more(lst, blocks);
}

void clear_stack_a(t_list *lst, t_block blocks)
{
    int pivot;
    int count;

    pivot = 0;
    count = 0;
    pivot = find_pivot((const int *)lst->stack_a, lst->size_a);
    count = find_count(lst->stack_a, lst->size_a, pivot);
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
    if (blocks.i == 0 && blocks.blocks[0] == 0)
        blocks.blocks[blocks.i]= lst->size_b;
    else
        blocks.blocks[blocks.i] = lst->size_b - dont_touch(blocks);
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
    lst->sort_in_a = lst->size_a;
}

void sort(t_list *lst)
{
    t_block blocks;
    int check;

    check = lst->size_a;
    ft_bzero(&blocks, sizeof(blocks));
    blocks.blocks = NULL;
    blocks.i = 0;
    if (lst->size_a <= 3)
        sort_three_elem(lst, blocks);
    else
    {
        while (lst->size_a > 3)
        {
            if (!blocks.blocks)
                blocks.blocks = (int *)ft_memalloc(sizeof(int) * 1024);
            clear_stack_a(lst, blocks);
            blocks.blocks[blocks.i] != 0 ? blocks.i++ : 0;
        }
        sort_three_elem(lst, blocks);
        while(check > lst->sort_in_a)
        {
            clear_stack_b(lst, blocks);
            if (blocks.i == 0 && blocks.blocks[0] == 0)
                blocks.blocks[blocks.i]= lst->size_b;
            else
                blocks.blocks[blocks.i] = lst->size_b - dont_touch(blocks);
            blocks.i++;
        }
    }
}