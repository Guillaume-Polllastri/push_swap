/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:51:44 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/10 10:02:19 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

static void	rotate(t_stack **stack)
{
	t_stack	*head;

	if (!(*stack) || !(*stack)->next)
		return ;
	head = *stack;
	*stack = head->next;
	head->next = NULL;
	ft_stacklast(*stack)->next = head;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(2, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(2, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(2, "rr\n", 3);
}
