/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:51:16 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/06 19:10:55 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft.h"

static int	index_element(int *tab, int element, int nb_elmt)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < nb_elmt)
	{
		if (element > tab[i])
			index++;
		i++;
	}
	return (index);
}

static int	where_is_max_index(t_stack *stack)
{
	int	max;
	int	i;
	int	pos;

	max = stack->index;
	i = 0;
	pos = 0;
	while (stack)
	{
		if (max < stack->index)
		{
			max = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

int	*fill_tab(t_stack **a, int nb_elmt)
{
	t_stack	*tmp_a;
	int		*tab;
	int		i;

	tab = malloc(sizeof(int) * (nb_elmt));
	i = 0;
	if (!tab)
		return (0);
	i = 0;
	tmp_a = *a;
	while (tmp_a)
	{
		tab[i] = tmp_a->content;
		tmp_a = tmp_a->next;
		i++;
	}
	return (tab);
}

void	fill_stack_index(t_stack **a, int *tab, int nb_elmt)
{
	int		i;
	t_stack	*tmp_a;

	i = 0;
	tmp_a = (*a);
	while (i < nb_elmt)
	{
		tmp_a->index = index_element(tab, tab[i], nb_elmt);
		tmp_a = tmp_a->next;
		i++;
	}
}

int	k_sort(t_stack **a, t_stack **b, int nb_elmt)
{
	int		count;
	int		*tab;
	int		i;
	double	range;
	int		index_b;

	count = 0;
	tab = fill_tab(a, nb_elmt);
	fill_stack_index(a, tab, nb_elmt);
	free(tab);
	i = 0;
	range = sqrt((double) nb_elmt) * 1.5;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			i++;
			rb(b);
			count += 2;
		}
		else if ((*a)->index <= (i + range))
		{
			pb(a, b);
			i++;
			count++;
		}
		else if ((*a)->index > (i + range))
		{
			ra(a);
			count++;
		}
	}
	while (*b)
	{
		index_b = where_is_max_index(*b);
		if (!index_b)
		{
			pa(a, b);
			count++;
		}
		if (index_b <= nb_elmt - index_b)
		{
			i = 0;
			while (i < index_b)
			{
				rb(b);
				count++;
				i++;
			}
		}
		else
		{
			i = 0;
			while (i < (nb_elmt - index_b))
			{
				rrb(b);
				count++;
				i++;
			}
		}
	}
	return (count);
}
