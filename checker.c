/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:29:07 by mbeahan           #+#    #+#             */
/*   Updated: 2019/08/03 23:33:46 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_op(t_list *lst, char *op)
{
	if (ft_strequ(op, "sa"))
		sa(lst, 0);
	else if (ft_strequ(op, "sb"))
		sb(lst, 0);
	else if (ft_strequ(op, "ss"))
		ss(lst);
	else if (ft_strequ(op, "pa"))
		pa(lst, 0);
	else if (ft_strequ(op, "pb"))
		pb(lst, 0);
	else if (ft_strequ(op, "ra"))
		ra(lst, 0);
	else if (ft_strequ(op, "rb"))
		rb(lst, 0);
	else if (ft_strequ(op, "rr"))
		rr(lst);
	else if (ft_strequ(op, "rra"))
		rra(lst, 0);
	else if (ft_strequ(op, "rrb"))
		rrb(lst, 0);
	else if (ft_strequ(op, "rrr"))
		rrr(lst);
	else
		return (-1);
	return (0);
}

static void do_ops(t_list *lst)
{
    char *op;

    while (get_next_line(0, &op) > 0)
    {
        if (!op)
            break ;
        if (get_op(lst, op))
        {
            ft_putstr_fd("Error\n", 2);
            free(lst->stack_a);
            free(lst->stack_b);
            free(lst);
            free(op);
            exit(1);
        }
        free(op);
        op = NULL;
    }
}

static void get_args(int ac, char **av, t_list *lst)
{
    av = ft_strsplit(av[0], ' ');
    ac = 0;
    while (av && av[ac])
        ac++;
    if (ac == 0)
    {
        ft_putstr_fd("Error\n", 2);
        free(lst);
        exit(1);
    }
}

int main (int ac, char **av)
{
    t_list *lst;
    int flags;

    (ac-- == 1) ? exit(0) : av++;
    lst = (t_list *)malloc(sizeof(t_list));
    flags = parse_flags(&ac, &av, lst);
    if (ac == 1)
        get_args(ac, av, lst);
    initialize(lst, ac);
    lst = fill_lst(lst, ac, av);
    lst->visualize = 0;
    do_ops(lst);
    if (sorted(lst->stack_a, lst->size_a) && lst->size_b == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free(lst->stack_a);
    free(lst->stack_b);
    free(lst);
	return (0);
}
