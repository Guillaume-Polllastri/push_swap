/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:55:04 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/14 13:43:56 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	is_sort_stack(t_stack *stack)
{
	int	i;

	if (!stack)
		return (1);
	i = stack->content;
	while (stack)
	{
		if (i <= stack->content)
			i = stack->content;
		else
			return (0);
		stack = stack->next;
	}
	return (1);
}

static t_info_stack	*min_stack(t_stack *stack)
{
	t_stack			*tmp;
	t_info_stack	*info;
	int				i;

	tmp = stack;
	info = malloc(sizeof(t_info_stack));
	info->min = stack->content;
	info->pos = 0;
	i = 0;
	while (tmp)
	{
		if (info->min > tmp->content)
		{
			info->min = tmp->content;
			info->pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (info);
}

static void	min_to_stack_b(t_stack **a, t_stack **b, int compteur)
{
	t_info_stack	*info;
	int				i;

	while (compteur > 0)
	{
		info = min_stack(*a);
		if (info->pos <= (ft_stacksize(*a) / 2))
		{
			i = info->pos;
			while (i--)
				ra(a);
		}
		else
		{
			i = ft_stacksize(*a) - info->pos;
			while (i--)
				rra(a);
		}
		pb(a, b);
		free(info);
		compteur--;
	}
}

static int	sort_for_3(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	if ((tmp->content < tmp->next->content)
		&& (tmp->content < tmp->next->next->content))
		return (sa(*a), rra(a), rra(a), 1);
	if ((tmp->content > tmp->next->content)
		&& (tmp->content < tmp->next->next->content))
		return (sa(*a), 1);
	if ((tmp->content < tmp->next->content)
		&& (tmp->content > tmp->next->next->content))
		return (rra(a), 1);
	if ((tmp->content > tmp->next->content)
		&& (tmp->next->content < tmp->next->next->content))
		return (ra(a), 1);
	else
		return (sa(*a), rra(a), 1);
}

int	cond_sort(t_stack **a, t_stack **b, int nb_elmt)
{
	int	compteur;

	if (nb_elmt == 2)
		return (ra(a), 1);
	if (nb_elmt == 3)
		return (sort_for_3(a));
	if (nb_elmt <= 5)
	{
		compteur = 3;
		min_to_stack_b(a, b, compteur);
		if (!is_sort_stack(*a))
			ra(a);
		while (*b)
			pa(a, b);
		return (1);
	}
	return (-1);
}
