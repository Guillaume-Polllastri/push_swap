/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:51:17 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/10 11:25:55 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

static t_stack	*swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return (stack);
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	return (stack);
}

void	sa(t_stack *a)
{
	swap(a);
	write(2, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(2, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(2, "ss\n", 3);
}
