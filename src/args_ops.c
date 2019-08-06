/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 15:59:03 by mbeahan           #+#    #+#             */
/*   Updated: 2019/08/06 20:00:12 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	initialize(t_list *lst, int ac)
{
	lst->stack_a = (int *)ft_memalloc(sizeof(int) * ac);
	lst->stack_b = (int *)ft_memalloc(sizeof(int) * ac);
	lst->size_a = ac;
	lst->size_b = 0;
	lst->sort_in_a = 0;
	lst->i = 0;
}

int		parse_ops(int *ac, char ***av, t_list *lst)
{
	int i;

	i = 0;
	lst->visualize = 0;
	while (i < *ac && *((*av)[i]) == '-')
	{
		if (ft_strequ((*av)[i], "-v"))
			lst->visualize = 1;
		else
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	*ac -= i;
	*av += i;
	return (i);
}

t_list	*fill_lst(t_list *lst, int ac, char **av)
{
	int i;

	i = 0;
	while (i < ac)
	{
		if (validate(av, av[i], i + 1))
			lst->stack_a[i] = ft_atoi(av[i]);
		else
		{
			free(lst->stack_a);
			free(lst->stack_b);
			free(lst);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (lst);
}

int		validate(char **av, char *ar, int begin)
{
	int i;

	i = 0;
	while (*ar && ar[i] != '\0')
	{
		if (!ft_isdigit(ar[i]) && ar[i] != '-')
			return (0);
		i++;
	}
	if (ft_atoi(ar) > INT_MAX || ft_atoi(ar) < INT_MIN)
		return (0);
	while (av[begin] && av && ar)
	{
		if (ft_strequ(av[begin], ar))
			return (0);
		begin++;
	}
	return (1);
}
