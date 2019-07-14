/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:15:20 by mbeahan           #+#    #+#             */
/*   Updated: 2019/07/14 19:08:16 by mbeahan          ###   ########.fr       */
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
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void 	ra(t_stack *stack_a, int print);
void 	rb(t_stack *stack_b, int print);
void 	rr(t_stack *stack_a, t_stack *stack_b);
void 	rra(t_stack *stack_a, int print);
void 	rrb(t_stack *stack_b, int print);
void    rrr(t_stack *stack_a, t_stack *stack_b);
void	ft_lstadd(t_stack **stack, t_stack *new, int num);
void    print_stack(t_stack *stack);


#endif
