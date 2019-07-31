/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:15:20 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/31 21:26:50 by mbeahan          ###   ########.fr       */
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
}              t_list;

typedef struct s_block
{
    int            sort_in_a;
    int            *blocks;
    int            i;
}              t_block;


void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void	ft_putendl_fd(char const *s, int fd);
char	**ft_strsplit(char const *s, char c);
int		ft_atoi(char *str);
void	ft_lstadd(t_block **alst, t_block *new);
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
void	init_blocks(t_block *block, t_list *lst);
int     dont_touch(t_block *block);
t_block *needed_block(t_block *block);
void    sort_three_elem(t_list *lst, t_block *a_block);
void    clear_stack_a(t_list *lst, t_block *a_block, t_block *b_block);
void    clear_stack_b(t_list *lst, t_block *a_block, t_block *b_block);
void    sort_stack_a(t_list *lst, t_block *a_block, int size);
int     find_count(const int *stack, int size, int pivot);
void    clear_stack_more(t_list *lst, t_block *a_block, t_block *b_block);
void    restore_stack(t_list *lst, int count);
#endif
