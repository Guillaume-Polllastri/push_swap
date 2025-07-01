/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:06:49 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/01 20:09:42 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmp_a;
	t_stack	*new;
	int		i;
	int		res;

	a = NULL;
	b = NULL;
	i = ac - 1;
	while (i > 0)
	{
		new = new_stack(ft_atoi(av[i]));
		new->next = a;
		a = new;
		i--;
	}
	res = radix_sort(&a, &b, ac - 1);
	tmp_a = a;
	while (tmp_a)
	{
		printf("%d\n", tmp_a->content);
		// printf("index : %d\n", tmp_a->index);
		tmp_a = tmp_a->next;
	}
	printf("%d operations\n", res);
	free_stacks(&a);
	return (0);
}
