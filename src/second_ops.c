/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:05:46 by mbeahan           #+#    #+#             */
/*   Updated: 2019/08/06 20:00:29 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_list *lst, int print)
{
	int i;
	int tmp;

	if (lst->size_a == 0)
		return ;
	i = 1;
	tmp = lst->stack_a[0];
	while (i < lst->size_a)
	{
		lst->stack_a[i - 1] = lst->stack_a[i];
		i++;
	}
	lst->stack_a[i - 1] = tmp;
	if (print)
		write(1, "ra\n", 3);
	if (lst->visualize)
		visualize(lst);
}

void	rb(t_list *lst, int print)
{
	int i;
	int tmp;

	if (lst->size_b == 0)
		return ;
	i = 1;
	tmp = lst->stack_b[0];
	while (i < lst->size_b)
	{
		lst->stack_b[i - 1] = lst->stack_b[i];
		i++;
	}
	lst->stack_b[i - 1] = tmp;
	if (print)
		write(1, "rb\n", 3);
	if (lst->visualize)
		visualize(lst);
}

void	rr(t_list *lst)
{
	if (lst)
	{
		ra(lst, 0);
		rb(lst, 0);
		write(1, "rr\n", 3);
		if (lst->visualize)
			visualize(lst);
	}
}

void	rra(t_list *lst, int print)
{
	int i;
	int tmp;

	if (lst->size_a == 0)
		return ;
	i = lst->size_a - 1;
	tmp = lst->stack_a[i];
	while (i > 0)
	{
		lst->stack_a[i] = lst->stack_a[i - 1];
		i--;
	}
	lst->stack_a[0] = tmp;
	if (print)
		write(1, "rra\n", 4);
	if (lst->visualize)
		visualize(lst);
}

void	rrb(t_list *lst, int print)
{
	int i;
	int tmp;

	if (lst->size_b == 0)
		return ;
	i = lst->size_b - 1;
	tmp = lst->stack_b[i];
	while (i > 0)
	{
		lst->stack_b[i] = lst->stack_b[i - 1];
		i--;
	}
	lst->stack_b[0] = tmp;
	if (print)
		write(1, "rrb\n", 4);
	if (lst->visualize)
		visualize(lst);
}
