/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:52:06 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/22 23:08:17 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sa(t_list *lst, int print)
{
    int tmp;
    int i;


    i = 0;
    tmp = 0;
    if (lst && lst->stack_a[0] && lst->stack_a[1])
    {
        while (i < lst->size_a - 2)
            i++;
        tmp = lst->stack_a[i];
        lst->stack_a[i] = lst->stack_a[i + 1];
        lst->stack_a[i + 1] = tmp;
        if (print)
            write(1, "sa\n", 3);
    }
    return (lst);
}

t_list	*sb(t_list *lst, int print)
{
    int tmp;
    int i;


    i = 0;
    tmp = 0;
    if (lst && lst->stack_b[0] && lst->stack_b[1])
    {
        while (i < lst->size_b - 2)
            i++;
        tmp = lst->stack_b[i];
        lst->stack_b[i] = lst->stack_b[i + 1];
        lst->stack_b[i + 1] = tmp;
        if (print)
            write(1, "sb\n", 3);
    }
    return (lst);
}

t_list	*ss(t_list *lst)
{
    if (lst->stack_a && lst->stack_b)
    {
        sa(lst, 0);
        sb(lst, 0);
        write(1, "ss\n", 3);
    }
    return (lst);
}

t_list *pa(t_list *lst)
{
    int i;
    int *new_b;
    int *new_a;

    lst->size_a++;
    lst->size_b--;
    i = 0;
    if (lst && lst->stack_a && lst->stack_b && lst->stack_b[0])
    {
        while (i < lst->size_b)
            i++;
        new_a = dup_stack(lst->stack_a, lst->size_a);
        new_a[lst->size_a] = lst->stack_b[i];
        free(lst->stack_a);
        lst->stack_a = new_a;
        new_b = dup_stack(lst->stack_b, lst->size_b);
        free(lst->stack_b);
        lst->stack_b = new_b;
        write(1, "pa\n", 3);
    }
    else
    {
        lst->stack_a = (int *)ft_memalloc(sizeof(int) * lst->size_a);
        while (i < lst->size_b)
            i++;
        lst->stack_a[0] = lst->stack_b[i];
        new_b = dup_stack(lst->stack_b, lst->size_b);
        free(lst->stack_b);
        lst->stack_b = new_b;
        write(1, "pa\n", 3);
    }
    return (lst);
}

t_list *pb(t_list *lst)
{
    int i;
    int *new_b;
    int *new_a;

    lst->size_a--;
    lst->size_b++;
    i = 0;
    if (lst && lst->stack_a && lst->stack_b && lst->stack_a[0])
    {
        while (i < lst->size_a)
            i++;
        new_b = dup_stack(lst->stack_b, lst->size_b);
        new_b[lst->size_b] = lst->stack_a[i];
        free(lst->stack_b);
        lst->stack_b = new_b;
        new_a = dup_stack(lst->stack_a, lst->size_a);
        free(lst->stack_a);
        lst->stack_a = new_a;
        write(1, "pb\n", 3);
    }
    else
    {
        lst->stack_b = (int *)ft_memalloc(sizeof(int) * lst->size_b);
        while (i < lst->size_a)
            i++;
        lst->stack_b[0] = lst->stack_a[i];
        new_a = dup_stack(lst->stack_a, lst->size_a);
        free(lst->stack_a);
        lst->stack_a = new_a;
        write(1, "pb\n", 3);
    }
    return (lst);
}