/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 16:06:00 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/14 21:13:20 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
    t_stack *a;
    t_stack *node;
    int i = 0;
    int j = 2;

    a = ft_memalloc(sizeof(a));
    a->num = av[1][0] - '0';
    a->next = NULL;
    while(i < ac - 2)
    {
        node = ft_memalloc(sizeof(node));
        ft_lstadd(&a, node, av[j][0] - '0');
        j++;
        i++;
    }
    printf("Your default stack is :\n");
    print_stack(a);
    printf("\nYour stack after operation is :\n");
    rra(a, 0);
    print_stack(a);
}