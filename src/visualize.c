/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:14:03 by mbeahan           #+#    #+#             */
/*   Updated: 2019/08/06 20:00:35 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	print_stacks(t_list *lst)
{
	int max;
	int i;

	i = 0;
	if (lst->size_a > lst->size_b)
		max = lst->size_a;
	else
		max = lst->size_b;
	ft_printf("Stack A: \t\tStack B: \n");
	while (i < max)
	{
		if (i < lst->size_a && i < lst->size_b)
			ft_printf("%d\t\t\t%d\n", lst->stack_a[i], lst->stack_b[i]);
		if (i < lst->size_a && !(i < lst->size_b))
			ft_printf("%d\n", lst->stack_a[i]);
		if (!(i < lst->size_a) && i < lst->size_b)
			ft_printf("%d\n", lst->stack_b[i]);
		i++;
	}
}

static void	print_stack(int *stack, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d\n", stack[i]);
		i++;
	}
}

void		visualize(t_list *lst)
{
	if (lst->size_a && !lst->size_b)
	{
		ft_printf("Stack A: \n");
		print_stack(lst->stack_a, lst->size_a);
		ft_printf("-----------\n");
	}
	if (!lst->size_a && lst->size_b)
	{
		ft_printf("Stack B: \n");
		print_stack(lst->stack_a, lst->size_a);
		ft_printf("-----------\n");
	}
	if (lst->size_a && lst->size_b)
	{
		print_stacks(lst);
		ft_printf("-----------\t\t-----------\n");
	}
}
