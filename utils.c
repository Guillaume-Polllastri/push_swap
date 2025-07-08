/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:39:21 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/08 15:20:47 by gpollast         ###   ########.fr       */
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

int	check_duplicate(char **av, int nb_elmt)
{
	int	i;
	int	j;

	j = 1;
	while (j < nb_elmt)
	{
		i = j + 1;
		while (i <= nb_elmt)
		{
			if (ft_atoi(av[j]) == ft_atoi(av[i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
