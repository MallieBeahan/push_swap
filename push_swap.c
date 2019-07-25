/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:26:10 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/25 12:56:21 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
    t_list *lst;

    lst = (t_list *)malloc(sizeof(lst));
    //ac == 0 ? ft_putendl_fd("Error\n", 2) : 0;
    if (ac > 1)
    {
        initialize(lst, ac);
        lst = fill_lst(lst, ac, av);
        sort(lst);
    }
}