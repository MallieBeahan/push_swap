/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:01:22 by mbeahan           #+#    #+#             */
/*   Updated: 2019/08/03 21:42:46 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	if (i != j)
		return (0);
	while (s1[k] != '\0' && s2[k] != '\0')
	{
		if (s1[k] != s2[k])
			return (0);
		k++;
	}
	return (1);
}
