/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:25:42 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/11 16:39:05 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

static int	instruction1(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		return (swap(*a), 1);
	if (!ft_strncmp(line, "sb\n", 3))
		return (swap(*b), 1);
	if (!ft_strncmp(line, "ss\n", 3))
		return (swap(*a), swap(*b), 1);
	return (0);
}

static int	instruction2(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "pa\n", 3))
	{
		if (!b || !(*b))
			return (0);
		return (push_elem(a, b), 1);
	}
	if (!ft_strncmp(line, "pb\n", 3))
	{
		if (!a || !(*a))
			return (0);
		return (push_elem(b, a), 1);
	}
	return (0);
}

static int	instruction3(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "ra\n", 3))
		return (rotate(a), 1);
	if (!ft_strncmp(line, "rb\n", 3))
		return (rotate(b), 1);
	if (!ft_strncmp(line, "rr\n", 3))
		return (rotate(a), rotate(b), 1);
	return (0);
}

static int	instruction4(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp(line, "rra\n", 4))
		return (reverse_rotate(a), 1);
	if (!ft_strncmp(line, "rrb\n", 4))
		return (reverse_rotate(b), 1);
	if (!ft_strncmp(line, "rrr\n", 4))
		return (reverse_rotate(a), reverse_rotate(b), 1);
	return (0);
}

int	check_instructions(t_stack **a, t_stack **b, char *line)
{
	if (instruction1(a, b, line))
		return (1);
	if (instruction2(a, b, line))
		return (1);
	if (instruction3(a, b, line))
		return (1);
	if (instruction4(a, b, line))
		return (1);
	return (0);
}
