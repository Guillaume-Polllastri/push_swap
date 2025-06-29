/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:44:22 by gpollast          #+#    #+#             */
/*   Updated: 2025/06/30 01:06:38 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*end;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	end = ft_stacklast((*stack));
	end->next = tmp;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	(*stack)->next = NULL;
	*stack = end;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
}
