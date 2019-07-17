/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 16:06:00 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/17 21:24:21 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
    t_stack *a;
    t_stack *node;
    t_stack *b;
    int i = 0;
    int j = 2;
    int size;
    size = 0;

    a = ft_memalloc(sizeof(a));
    a->num = av[1][0] - '0';
    a->filled = 1;
    a->next = NULL;
    while(i < ac - 2)
    {
        node = ft_memalloc(sizeof(node));
        ft_lstadd(&a, node, av[j][0] - '0', 1);
        j++;
        i++;
    }
    size = lst_size(a);
    if (size == 2)
        sa(a, 1);
    if (size == 3)
        first_case(&a);
    if (size > 3 && size < 10)
    {
        b = create_b(size);
        second_case(a, b, size);
    }
    // printf("Your default stack is :\n");
    // print_stack(a);
    // printf("\nYour stack after operation is :\n");
    // print_stack(a);
}