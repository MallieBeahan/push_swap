/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:15:20 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/31 23:34:44 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_list
{
    int *stack_a;
    int *stack_b;
    int size_a;
    int size_b;
    int bl_a_count;
    int bl_b_count;
    int sort_in_a;
}              t_list;

typedef struct s_block
{
    int            *blocks;
    int            i;
}              t_block;


void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	ft_putendl_fd(char const *s, int fd);
char	**ft_strsplit(char const *s, char c);
int		ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
void    initialize(t_list *lst, int ac);
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
int		*copyarr(const int *arr, int k);
int		*sort_arr(int *arr, int size);
int		find_pivot(const int *arr, int size);
void	sort(t_list *lst);
int     dont_touch(t_block block);
void    sort_three_elem(t_list *lst, t_block blocks);
void    clear_stack_a(t_list *lst, t_block blocks);
void    clear_stack_b(t_list *lst, t_block blocks);
void    sort_stack_a(t_list *lst, t_block blocks, int size);
int     find_count(const int *stack, int size, int pivot);
void    clear_stack_more(t_list *lst, t_block blocks);
void    restore_stack(t_list *lst, int count);
void    print_stack(t_list *lst);
#endif
