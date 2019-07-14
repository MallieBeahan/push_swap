/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:57:43 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/12 17:48:11 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (str)
	{
		while (i < size)
		{
			str[i] = '\0';
			i++;
		}
		return (str);
	}
	return (NULL);
}
