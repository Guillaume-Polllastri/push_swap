/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:42:31 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/14 14:11:39 by gpollast         ###   ########.fr       */
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

static int	check_args(t_stack **a, t_args *args, int ac, char **av)
{
	if (!parse_args(args, ac, av))
		return (free_string_array(args->array), free(args), 0);
	if (!validate_args(args))
		return (free_string_array(args->array), free(args), 0);
	if (!fill_stack(a, args))
		return (free_string_array(args->array), free(args), free_stacks(a), 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_args	*args;

	if (ac <= 1)
		return (1);
	a = NULL;
	b = NULL;
	args = malloc(sizeof(t_args));
	if (!args)
		return (1);
	if (!check_args(&a, args, ac, av))
		return (1);
	free_string_array(args->array);
	free(args);
	read_standard_input(&a, &b);
	if (!a)
		return (write(1, "Error\n", 6), 1);
	if (is_sort_stack(a) && !b)
		return (free_stacks(&a), write(1, "OK\n", 3), 0);
	else
		return (free_stacks(&a), write(1, "KO\n", 3), 0);
}
