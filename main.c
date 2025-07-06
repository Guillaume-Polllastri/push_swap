/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:06:49 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/06 17:58:36 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft.h"

static int	is_sort_stack(t_stack**stack)
{
	int	i;

	i = (*stack)->content;
	while ((*stack))
	{
		if (i <= (*stack)->content)
			i = (*stack)->content;
		else
			return (0);
		*stack = (*stack)->next;
	}
	return (1);
}

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
	res = k_sort(&a, &b, ac - 1);
	tmp_a = a;
	while (tmp_a)
	{
		printf("%d\n", tmp_a->content);
		tmp_a = tmp_a->next;
	}
	printf("%d operations\n", res);
	if (is_sort_stack(&a) == 1)
		printf("La liste est triee\n");
	else
		printf("NOP\n");
	free_stacks(&a);
	return (0);
}
