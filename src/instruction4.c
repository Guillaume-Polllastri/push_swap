/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:51:51 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/10 10:11:07 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*end;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	end = ft_stacklast((*stack));
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	end->next = tmp;
	(*stack)->next = NULL;
	*stack = end;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(2, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(2, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(2, "rrr\n", 4);
}
