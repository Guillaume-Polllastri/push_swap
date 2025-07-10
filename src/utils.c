/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:39:21 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/10 14:16:22 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

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

double	sqrt(double nb)
{
	double	x;
	double	guess;
	double	epsilon;

	if (nb < 0)
		return (-1);
	x = nb;
	guess = nb / 2.0;
	epsilon = 0.000001;
	if (nb == 0 || nb == 1)
		return (nb);
	while ((guess * guess - x) > epsilon || (guess * guess - x) < -epsilon)
		guess = (guess + x / guess) / 2.0;
	return (guess);
}
