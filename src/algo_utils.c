/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:41:50 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/10 17:58:41 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include "stdio.h"

int	index_element(int *tab, int element, int nb_elmt)
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

t_info_stack	where_is_max_index(t_stack *stack)
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
