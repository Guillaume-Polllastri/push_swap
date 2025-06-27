/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:06:49 by gpollast          #+#    #+#             */
/*   Updated: 2025/06/27 16:54:40 by gpollast         ###   ########.fr       */
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
	t_stack	*tmp_a;
	int		i;

	a = NULL;
	// b = NULL;
	i = 1;
	while (i < ac)
	{
		a = stack_push(a, ft_atoi(av[i]));
		i++;
	}
	tmp_a = a;
	while (tmp_a)
	{
		printf("%d\n", tmp_a->content);
		tmp_a = tmp_a->next;
	}
	printf("- -\na b\n\nswap a\n");
	a = swap(a);
	tmp_a = a;
	while (tmp_a)
	{
		printf("%d\n", tmp_a->content);
		tmp_a = tmp_a->next;
	}
	printf("- -\na b\n\n");
	a = stack_pop(a);
	tmp_a = a;
	while (tmp_a)
	{
		printf("%d\n", tmp_a->content);
		tmp_a = tmp_a->next;
	}
	return (0);
}
