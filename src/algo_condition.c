/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:55:04 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/10 15:03:47 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

static int	is_sort_stack(t_stack**stack)
{
	int	i;

	i = (*stack)->content;
	while ((*stack))
	{
		if (i <= (*stack)->content)
			i = (*stack)->content;
		else
			return (0);
		*stack = (*stack)->next;
	}
	return (1);
}

int	cond_sort(t_stack **a, t_stack **b, int nb_elmt)
{
	(void)b;
	if (nb_elmt == 1)
	{
		return (1);
	}
	if (nb_elmt == 2)
	{
		if (is_sort_stack(a))
			return (1);
		ra(a);
		return (1);
	}
	return (-1);
}
