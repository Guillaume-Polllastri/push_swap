/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:40:17 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/06 19:14:19 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info_stack
{
	int	max;
	int	pos;
}	t_info_stack;

/* ************************************************************************** */

int		ft_stacksize(t_stack *stack);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*stack_push(t_stack *tail, t_stack *element);
void	stack_destroy(t_stack *head);
t_stack	*new_stack(int content);
t_stack	*stack_pop(t_stack *stack);
void	free_stacks(t_stack **stack);
double	sqrt(double nb);

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

void	fill_stack_index(t_stack **a, int *tab, int nb_elmt);
int		*fill_tab(t_stack **a, int nb_elmt);
int		k_sort(t_stack **a, t_stack **b, int nb_elmt);

#endif