/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:55:04 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/09 18:07:25 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "libft.h"

int	cond_sort(t_stack **a, t_stack **b, int nb_elmt)
{
	if (nb_elmt == 1)
	{
		return (0);
	}
	if (nb_elmt == 2)
	{
		if (is_sort_stack(a))
			return (0);
		ra(a);
		return (1);
	}
	return (-1);
}