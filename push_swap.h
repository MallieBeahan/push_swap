/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:15:20 by mbeahan           #+#    #+#             */
/*   Updated: 2019/08/03 23:24:52 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
    int *stack_a;
    int *stack_b;
    int size_a;
    int size_b;
    int sort_in_a;
    int i;
    int visualize;
}              t_list;

typedef struct s_block
{
    int            *blocks;
    int            i;
}              t_block;

void    initialize(t_list *lst, int ac);
int     parse_flags(int *ac, char ***av, t_list *lst);
t_list	*fill_lst(t_list *lst, int ac, char **av);
void 	sa(t_list *lst, int print);
void 	sb(t_list *lst, int print);
void    ss(t_list *lst);
void	pa(t_list *lst, int print);
void	pb(t_list *lst, int print);
void    ra(t_list *lst, int print);
void    rb(t_list *lst, int print);
void    rr(t_list *lst);
void    rra(t_list *lst, int print);
void    rrb(t_list *lst, int print);
void    rrr(t_list *lst);
int     validate(char **av, char *ar, int begin);
int		*copyarr(const int *arr, int k);
int		*sort_arr(int *arr, int size);
int		find_pivot(const int *arr, int size);
void	sort(t_list *lst);
int     dont_touch(t_block block, int size);
void    sort_three_elem(t_list *lst, t_block blocks);
void    clear_stack_a(t_list *lst, t_block blocks);
void    clear_stack_b(t_list *lst, t_block blocks);
void    sort_stack_a(t_list *lst, t_block blocks, int size);
int     find_count(const int *stack, int size, int pivot);
void    clear_stack_more(t_list *lst, t_block blocks);
void    restore_stack(t_list *lst, int count);
void    print_stack(t_list *lst);
void    free_all(t_block blocks, t_list *lst);
int     sorted(int *stack, int len);

#endif
