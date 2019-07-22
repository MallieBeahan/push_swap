/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:52:49 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/22 23:44:59 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *rr(t_list *lst)
{
    if (lst)
    {
        ra(lst, 0);
        rb(lst, 0);
        write(1, "rr\n", 3);
    }
    return (lst);
}

t_list *ra(t_list *lst, int print)
{
    int tmp;
    int i;
    
    i = 0;
    tmp = 0;
    if (lst && lst->stack_a[0] && lst->stack_a[1])
    {
        while (i < lst->size_a - 1)
            i++;
        while (i)
        {
            tmp = lst->stack_a[i];
            lst->stack_a[i] = lst->stack_a[i - 1];
            lst->stack_a[i - 1] = tmp;
            i--;
        }
        if (print)
            write(1, "ra\n", 4);
    }
    return (lst);
}

t_list *rb(t_list *lst, int print)
{
    int tmp;
    int i;
    
    i = 0;
    tmp = 0;
    if (lst && lst->stack_b[0] && lst->stack_b[1])
    {
        while (i < lst->size_b - 1)
            i++;
        while (i)
        {
            tmp = lst->stack_b[i];
            lst->stack_b[i] = lst->stack_b[i - 1];
            lst->stack_b[i - 1] = tmp;
            i--;
        }
        if (print)
            write(1, "rb\n", 4);
    }
    return (lst);
}

t_list *rrr(t_list *lst)
{
    if (lst)
    {
        rra(lst, 0);
        rrb(lst, 0);
        write(1, "rrr\n", 3);
    }
    return(lst);
}

t_list *rra(t_list *lst, int print)
{
    int tmp;
    int i;

    i = 0;
    tmp = 0;
    if (lst && lst->stack_a[0] && lst->stack_a[1])
    {
        while(i < lst->size_a - 1)
        {
            tmp = lst->stack_a[i];
            lst->stack_a[i] = lst->stack_a[i + 1];
            lst->stack_a[i + 1] = tmp;
            i++;
        }
        if (print)
            write(1, "rra\n", 3);
    }
    return (lst);
}

t_list *rrb(t_list *lst, int print)
{
    int tmp;
    int i;

    i = 0;
    tmp = 0;
    if (lst && lst->stack_b[0] && lst->stack_b[1])
    {
        while(i < lst->size_b - 1)
        {
            tmp = lst->stack_b[i];
            lst->stack_b[i] = lst->stack_b[i + 1];
            lst->stack_b[i + 1] = tmp;
            i++;
        }
        if (print)
            write(1, "rrb\n", 3);
    }
    return (lst);
}