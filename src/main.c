/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:06:49 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/13 19:34:20 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

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
		return (free_string_array(args->array), free(args), 1);
	if (!validate_args(args))
		return (free_string_array(args->array), free(args), 1);
	if (!fill_stack(&a, args))
		return (free_string_array(args->array), free(args), free_stacks(&a), 1);
	free_string_array(args->array);
	if (is_sort_stack(a))
		return (free(args), free_stacks(&a), 0);
	if (cond_sort(&a, &b, args->size) != -1)
		return (free(args), free_stacks(&a), 0);
	if (k_sort(&a, &b, args->size) == -1)
		return (free_stacks(&a), 1);
	free(args);
	free_stacks(&a);
	return (0);
}
