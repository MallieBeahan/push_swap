/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 16:06:00 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/22 23:27:10 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
    int i;
    int j;
    t_list *lst;

    i = 0;
    j = 1;
    lst = (t_list *)ft_memalloc(sizeof(lst));
    lst->stack_a = (int *)ft_memalloc(sizeof(int) * (ac - 1));
    while(i < ac - 1)
    {
        lst->stack_a[i] = ft_atoi(av[j]);
        i++;
        j++;
    }
    lst->size_a = ac - 1;
    rra(lst, 1);
    // if (size == 2)
    //     sa(a, 1);
    // if (size == 3)
    //     first_case(&a);
    // if (size > 3 && size < 101)
    //     second_case(a, size);
}