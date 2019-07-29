/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:36:34 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/26 19:42:50 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd(t_block **alst, t_block *new)
{
	if (alst && new)
	{
		new->next = *alst;
		new->bl_size = 0;
		*alst = new;
	}
}
