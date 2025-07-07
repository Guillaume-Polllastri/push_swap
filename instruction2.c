/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:51:30 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/07 12:58:24 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

static	void	push_elem(t_stack **in, t_stack **out)
{
	if (!(*out))
		return ;
	*in = stack_push(*in, *out);
	*out = stack_pop(*out);
}

void	pa(t_stack **a, t_stack **b)
{
	if (!b || !(*b))
		return ;
	push_elem(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	if (!a || !(*a))
		return ;
	push_elem(b, a);
	ft_printf("pb\n");
}