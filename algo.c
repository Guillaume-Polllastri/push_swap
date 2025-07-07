/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:51:16 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/07 16:48:02 by gpollast         ###   ########.fr       */
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

static t_info_stack	where_is_max_index(t_stack *stack)
{
	t_info_stack	info;
	int				i;

	info.max = stack->index;
	i = 0;
	info.pos = 0;
	while (stack)
	{
		if (info.max < stack->index)
		{
			info.max = stack->index;
			info.pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (info);
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

static int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	k_sort(t_stack **a, t_stack **b, int nb_elmt)
{
	int		count;
	int		*tab;
	int		i;
	double	range;
	t_info_stack	info;

	count = 0;
	tab = fill_tab(a, nb_elmt);
	fill_stack_index(a, tab, nb_elmt);
	free(tab);
	i = 0;
	range = sqrt((double) nb_elmt) * 1.5;
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
	while (*b)
	{
		info = where_is_max_index(*b);
		if (info.pos <= stack_size(*b) / 2)
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
