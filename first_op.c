/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:05:52 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/25 13:00:11 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	sa(t_list *lst, int print)
{
	int tmp;

	if (lst->size_a < 2)
		return ;
	tmp = lst->stack_a[lst->size_a - 1];
	lst->stack_a[lst->size_a - 1] = lst->stack_a[lst->size_a - 2];
	lst->stack_a[lst->size_a - 2] = tmp;
	if(print)
        write(1, "sa\n", 3);
}

void 	sb(t_list *lst, int print)
{
	int tmp;

	if (lst->size_b < 2)
		return ;
	tmp = lst->stack_b[lst->size_b - 1];
	lst->stack_b[lst->size_b - 1] = lst->stack_b[lst->size_b - 2];
	lst->stack_b[lst->size_b - 2] = tmp;
	if(print)
        write(1, "sb\n", 3);
}

void	ss(t_list *lst)
{
	if (lst)
	{
		sa(lst, 0);
		sb(lst, 0);
		write(1, "ss\n", 3);
	}
}

void	pa(t_list *lst, int print)
{
	if (lst->size_b == 0)
		return ;
	lst->stack_a[lst->size_a + 1] = lst->stack_b[lst->size_b - 1];
	lst->size_a++;
	lst->size_b--;
	if(print)
		write(1, "pa\n", 3);
}

void	pb(t_list *lst, int print)
{
	if (lst->size_a == 0)
		return ;
	lst->stack_b[lst->size_b] = lst->stack_a[lst->size_a - 1];
	lst->size_b++;
	lst->size_a--;
	if(print)
		write(1, "pb\n", 3);
}