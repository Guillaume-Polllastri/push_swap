/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:51:16 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/03 14:35:26 by gpollast         ###   ########.fr       */
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

static int	max_bits(int *tab, int nb_elmt)
{
	int	max;
	int	i;
	int	bit;

	i = 0;
	max = tab[0];
	while (i < nb_elmt)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	i = 7;
	while (i >= 0)
	{
		bit = ((max >> i) & 1);
		if (bit == 1)
			return (i);
		i--;
	}
	return (0);
}

int	radix_sort(t_stack **a, t_stack **b, int nb_elmt)
{
	int		i;
	int		j;
	char	bit;
	int		*tab;
	int		count;

	i = 0;
	bit = 0;
	count = 0;
	tab = fill_tab(a, nb_elmt);
	fill_stack_index(a, tab, nb_elmt);
	while (i < max_bits(tab, nb_elmt))
	{
		j = 0;
		while (j < nb_elmt)
		{
			bit = (((*a)->index >> i) & 1);
			if (bit == 0)
			{
				pb(a, b);
				count++;
			}
			else
			{
				ra(a);
				count++;
			}
			j++;
		}
		while ((*b))
		{
			pa(a, b);
			count++;
		}
		if (is_sort_stack(a))
			return (count);
		i++;
		printf("\n");
	}
	free(tab);
	return (count);
}
