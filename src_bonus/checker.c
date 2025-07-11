/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:42:31 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/11 17:10:18 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include "../includes/get_next_line.h"
#include <stdio.h>

static int	read_standard_input(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	if (!line)
		return (1);
	while (line)
	{
		if (!check_instructions(a, b, line))
			return (free(line), 1);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_args	*args;

	a = NULL;
	b = NULL;
	args = malloc(sizeof(t_args));
	if (!args)
		return (1);
	if (!parse_args(args, ac, av))
		return (free(args), 1);
	if (!validate_args(args))
		return (free_string_array(args->array), free(args), 1);
	fill_stack(&a, args);
	free_string_array(args->array);
	free(args);
	if (!read_standard_input(&a, &b))
	{
		if (is_sort_stack(a))
			return (free_stacks(&a), write(1, "OK\n", 3), 0);
		return (free_stacks(&a), write(1, "KO\n", 3), 0);
	}
	free_stacks(&a);
	return (write(2, "Error\n", 6), 1);
}
