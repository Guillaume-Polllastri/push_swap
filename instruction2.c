/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:41:44 by gpollast          #+#    #+#             */
/*   Updated: 2025/06/29 19:16:58 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

static	void	push_elem(t_stack **in, t_stack **out)
{
	if (!(*out))
		return ;
	*in = stack_push(*in, (*out)->content);
	*out = stack_pop(*out);
}

void	pa(t_stack **a, t_stack **b)
{
	if (!b)
		return ;
	push_elem(a, b);
}

void	pb(t_stack **a, t_stack **b)
{
	if (!a)
		return ;
	push_elem(b, a);
}