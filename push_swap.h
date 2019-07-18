/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:15:20 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/18 21:40:18 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_stack
{
    int				num;
    struct s_stack	*next;
}				t_stack;

void	ft_bzero(void *s, size_t n);
void	*ft_memalloc(size_t size);
void 	sa(t_stack *stack_a, int print);
void 	sb(t_stack *stack_b, int print);
void 	ss(t_stack *stack_a, t_stack *stack_b);
t_stack	*pa(t_stack *stack_a, t_stack *stack_b);
t_stack	*pb(t_stack *stack_a, t_stack *stack_b);
void 	ra(t_stack *stack_a, int print);
void 	rb(t_stack *stack_b, int print);
void 	rr(t_stack *stack_a, t_stack *stack_b);
void 	rra(t_stack *stack_a, int print);
void 	rrb(t_stack *stack_b, int print);
void    rrr(t_stack *stack_a, t_stack *stack_b);
void	ft_lstadd(t_stack **stack, t_stack *new, int num);
void    print_stack(t_stack *stack);
int     lst_size(t_stack *stack);
void    first_case(t_stack **stack_a);
t_stack *create_b(int size);
void second_case(t_stack *stack_a, int size);
int find_digit(t_stack *lst,int size);
t_stack *help_func_ten(int first, int second, t_stack *stack_a, t_stack *stack_b, int size);
int check_digit(t_stack *stack_a, int digit, int check);
t_stack *help_func_less(int first, t_stack *stack_a, t_stack *stack_b, int size);
void push_b_to_a(t_stack *a, t_stack *b, int size);
t_stack	*ft_lstnew(t_stack **stack, int num);
int		ft_atoi(char *str);
int what_to_do(int pos_first, int pos_second, int size);
#endif
