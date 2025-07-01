/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:40:17 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/01 12:04:29 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

/* ************************************************************************** */

int		ft_stacksize(t_stack *stack);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*stack_push(t_stack *tail, int content);
void	stack_destroy(t_stack *head);
t_stack	*stack_pop(t_stack *stack);
void	free_stacks(t_stack **stack);

/* ************************************************************************** */

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* ************************************************************************** */

int		*tab_index(int *tab, int nb_elmt);

#endif