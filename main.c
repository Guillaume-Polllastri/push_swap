/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:06:49 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/01 12:07:48 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	int		*tab;
	int		*new_tab;
	int		i;

	a = NULL;
	tab = malloc(sizeof(int) * (ac - 1));
	if (!tab)
		return (0);
	i = 1;
	while (i < ac)
	{
		tab[i - 1] = ft_atoi(av[i]);
		i++;
	}
	i = ac - 1;
	while (i > 0)
	{
		a = stack_push(a, ft_atoi(av[i]));
		i--;
	}
	i = 0;
	new_tab = tab_index(tab, ac - 1);
	if (new_tab)
		return (free(tab), free(new_tab), free_stacks(&a), 0);
	while (i < ac - 1)
	{
		printf("index : %d\n", tab[i]);
		i++;
	}
	free(tab);
	free(new_tab);
	free_stacks(&a);
	return (0);
}
