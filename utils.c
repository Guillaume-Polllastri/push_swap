/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:39:21 by gpollast          #+#    #+#             */
/*   Updated: 2025/06/30 00:43:07 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	ft_stacksize(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	int	last_e;

	last_e = ft_stacksize(stack);
	while (last_e > 1)
	{
		stack = stack->next;
		last_e--;
	}
	return (stack);
}
