/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 16:06:00 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/18 20:56:33 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
    t_stack *a;
    t_stack *node;
    int i = 0;
    int j = 2;
    int size;
    size = 0;
    a = ft_memalloc(sizeof(a));
    a->num = ft_atoi(&av[1][0]);
    a->next = NULL;
    while(i < ac - 2)
    {
        node = ft_memalloc(sizeof(node));
        ft_lstadd(&a, node, ft_atoi(&av[j][0]));
        j++;
        i++;
    }
    size = lst_size(a);
    if (size == 2)
        sa(a, 1);
    if (size == 3)
        first_case(&a);
    if (size > 3 && size < 101)
        second_case(a, size);
    // printf("Your default stack is :\n");
    // print_stack(a);
    // printf("\nYour stack after operation is :\n");
    // print_stack(a);
}