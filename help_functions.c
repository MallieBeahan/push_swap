/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:49:32 by mbeahan           #+#    #+#             */
/*   Updated: 2019/08/03 20:52:03 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int validate(char **av, char *ar, int begin)
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

void	initialize(t_list *lst, int ac)
{
	lst->stack_a = (int *)ft_memalloc(sizeof(int) * ac);
	lst->stack_b = (int *)ft_memalloc(sizeof(int) * ac);
	lst->size_a = ac;
	lst->size_b = 0;
    lst->sort_in_a = 0;
    lst->i = 0;
}

int parse_flags(int *ac, char ***av, t_list *lst)
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
            exit (1);
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

void	rrr(t_list *lst)
{
    if (lst)
    {
        rra(lst, 0);
        rrb(lst, 0);
        write(1, "rrr\n", 4);
    }
}

int	*copyarr(const int *arr, int k)
{
	int i;
	int *copy;

	i = 0;
	copy = (int *)malloc(sizeof(int) * k + 1);
	while (i < k)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
}


int		find_pivot(const int *arr, int size)
{
	int *new_arr;
    int pivot;

    pivot = 0;
    new_arr = copyarr(arr, size);
    sort_arr(new_arr, size);
    if (size % 2 == 0)
        pivot = ((new_arr[size / 2] + new_arr[(size / 2) - 1]) / 2);
    else
        pivot = new_arr[size / 2];
    free(new_arr);
    return (pivot);
}