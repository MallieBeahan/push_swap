/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:15:20 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/22 23:45:16 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_list
{
    int				*stack_a;
    int             *stack_b;
    int             size_a;
    int             size_b;
    int             start_a;
    int             start_b;
}				t_list;

void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
int     *dup_stack(int *stack, int size);
t_list	*sa(t_list *lst, int print);
t_list	*sb(t_list *lst, int print);
t_list	*ss(t_list *lst);
t_list	*pa(t_list *lst);
t_list	*pb(t_list *lst);
t_list	*ra(t_list *lst, int print);
t_list	*rb(t_list *lst, int print);
t_list	*rr(t_list *lst);
t_list 	*rra(t_list *lst, int print);
t_list	*rrb(t_list *lst, int print);
t_list	*rrr(t_list *lst);
// void    print_stack(t_list *lst);
// int     lst_size(t_list *lst);
// void    first_case(t_stack **stack_a);
// t_stack *create_b(int size);
// void second_case(t_stack *stack_a, int size);
// int find_digit(t_stack *lst,int size);
// t_stack *help_func_ten(int first, int second, t_stack *stack_a, t_stack *stack_b, int size);
// int check_digit(t_stack *stack_a, int digit, int check);
// t_stack *help_func_less(int first, t_stack *stack_a, t_stack *stack_b, int size);
// void push_b_to_a(t_stack *a, t_stack *b, int size);
// t_stack	*ft_lstnew(t_stack **stack, int num);
int		ft_atoi(char *str);
int *dup_stack(int *stack, int size);
// int what_to_do(int pos_first, int pos_second, int size);
// t_stack *push_second_digit (int pos, t_stack *stack_a, t_stack *stack_b, int size);
// int find_pos(t_stack *stack, int digit);
#endif
