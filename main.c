/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:06:49 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/10 15:07:08 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_args	*args;

	a = NULL;
	b = NULL;
	args = malloc(sizeof(t_args));
	if (!parse_args(args, ac, av))
		return (1);
	if (!validate_args(args))
		return (1);
	fill_stack(&a, args);
	free_string_array(args->array);
	if (k_sort(&a, &b, args->size) == -1)
		return (free_stacks(&a), 1);
	free(args);
	free_stacks(&a);
	return (0);
}
