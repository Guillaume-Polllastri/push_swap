/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:06:49 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/08 18:08:34 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft.h"

// static int	is_sort_stack(t_stack**stack)
// {
// 	int	i;

// 	i = (*stack)->content;
// 	while ((*stack))
// 	{
// 		if (i <= (*stack)->content)
// 			i = (*stack)->content;
// 		else
// 			return (0);
// 		*stack = (*stack)->next;
// 	}
// 	return (1);
// }

static int	is_int_args(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			&& (!(str[i] >= '0' && str[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	// t_stack	*tmp_a;
	t_stack	*new;
	int		i;
	char	*str;

	i = 1;
	while (i < ac)
	{
		if (!is_int_args(av[i]))
			return (write(2, "Error\n", 6), 1);
		i++;
	}
	i = 1;
	while (i < ac)
	{
		ft_substr(av[i], );
	}
	if (!check_duplicate(av, (ac - 1)))
		return (write(2, "Error\nDuplicated numbers\n", 16) , 1);
	i = 0;
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
	if (k_sort(&a, &b, ac - 1) == -1)
		return (free_stacks(&a), 1);
	// tmp_a = a;
	// while (tmp_a)
	// {
	// 	printf("%d\n", tmp_a->content);
	// 	tmp_a = tmp_a->next;
	// }
	// printf("%d operations\n", k_sort(&a, &b, ac - 1));
	// if (is_sort_stack(&a) == 1)
	// 	printf("La liste est triee\n");
	// else
	// 	printf("NOP\n");
	free_stacks(&a);
	return (0);
}
