/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:26:10 by mbeahan           #+#    #+#             */
/*   Updated: 2019/08/03 23:03:09 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
    t_list *lst;
    int flags;

    (ac-- == 1) ? exit(0) : av++;
    lst = (t_list *)malloc(sizeof(t_list));
    flags = parse_flags(&ac, &av, lst);
    if (ac == 1)
    {
        av = ft_strsplit(av[0], ' ');
        ac = 0;
        while (av && av[ac])
            ac++;
        if (ac == 0)
        {
            ft_putstr_fd("Error\n", 2);
            exit(1);
        }
    }
    initialize(lst, ac);
    lst = fill_lst(lst, ac, av);
    if (sorted(lst->stack_a, lst->size_a))
    {
        free(lst->stack_a);
        free(lst->stack_b);
        free(lst);
    }
    else
        sort(lst);
    return (0);
}