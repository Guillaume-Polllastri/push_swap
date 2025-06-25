/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:06:49 by gpollast          #+#    #+#             */
/*   Updated: 2025/06/25 21:04:52 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	// t_stack	*b;
	int		i;

	a = NULL;
	// b = NULL;
	i = 1;
	while (i < ac)
	{
		a = stack_push(a, ft_atoi(av[i]));
		i++;
	}
	while (a)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
	return (0);
}