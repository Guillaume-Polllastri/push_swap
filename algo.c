/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:51:16 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/01 11:59:29 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

int	*tab_index(int *tab, int nb_elmt)
{
	int	i;
	int	*new_tab;

	i = 0;
	new_tab = malloc(sizeof(int) * nb_elmt);
	if (!new_tab)
		return (NULL);
	while (i < nb_elmt)
	{
		new_tab[i] = index_element(tab, tab[i], nb_elmt);
		i++;
	}
	return (new_tab);
}
