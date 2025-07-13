/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:51:16 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/13 19:36:52 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

static int	k_distribution(t_stack **a, t_stack **b, double range)
{
	int	i;
	int	count;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= (i + range))
		{
			pb(a, b);
			count++;
			if ((*b)->index <= i)
			{
				rb(b);
				count++;
			}
			i++;
		}
		else
		{
			ra(a);
			count++;
		}
	}
	return (count);
}

static int	reintegration(t_stack **a, t_stack **b, int count)
{
	t_info_stack	info;

	while (*b)
	{
		info = where_is_max_index(*b);
		if (info.pos <= ft_stacksize(*b) / 2)
		{
			while ((*b)->index != info.max)
			{
				rb(b);
				count++;
			}
		}
		else
		{
			while ((*b)->index != info.max)
			{
				rrb(b);
				count++;
			}
		}
		pa(a, b);
		count++;
	}
	return (count);
}

int	k_sort(t_stack **a, t_stack **b, int nb_elmt)
{
	int				count;
	int				*tab;
	double			range;

	count = 0;
	tab = fill_tab(a, nb_elmt);
	if (!tab)
		return (-1);
	fill_stack_index(a, tab, nb_elmt);
	free(tab);
	range = sqrt((double) nb_elmt) * 1.5;
	k_distribution(a, b, range);
	reintegration(a, b, count);
	return (count);
}
