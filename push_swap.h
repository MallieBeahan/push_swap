/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:15:20 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/29 20:47:57 by mbeahan          ###   ########.fr       */
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
}              t_list;

typedef struct s_block
{
    int            bl_size;
    struct s_block *next;
    
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

#endif
