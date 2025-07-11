/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 10:32:56 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/11 09:26:40 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

static int	check_duplicate(char **av, int nb_elmt)
{
	int	i;
	int	j;

	j = 0;
	while (j < nb_elmt)
	{
		i = j + 1;
		while (i < nb_elmt)
		{
			if (ft_atoi(av[j]) == ft_atoi(av[i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

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
		if (!(str[i] == ' ') && (!(str[i] >= '0' && str[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

static int	check_int_value(char *str)
{
	char	*cmp;

	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			cmp = STR_MIN_INT;
		str++;
	}
	else
		cmp = STR_MAX_INT;
	if (ft_strlen(str) == ft_strlen(cmp))
		return (ft_strncmp(cmp, str, ft_strlen(cmp)));
	else
		return (ft_strlen(cmp) - ft_strlen(str));
}

int	parse_args(t_args *args, int ac, char **av)
{
	int		i;
	char	**split;
	char	**temp;

	i = 1;
	args->size = 0;
	args->array = malloc(sizeof(char *));
	if (!args->array)
		return (0);
	args->array[0] = NULL;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		temp = args->array;
		args->array = string_array_concat(args->array, split);
		free_string_array(temp);
		free_string_array(split);
		i++;
	}
	while (args->array[args->size])
		args->size++;
	return (1);
}

int	validate_args(t_args *args)
{
	int		i;

	i = 0;
	while (i < args->size)
	{
		if (!is_int_args(args->array[i]))
			return (write(2, "Error\nArgument is not a int\n", 28), 0);
		if (check_int_value(args->array[i]) < 0)
			return (write(2, "Error\nArgument is not a int\n", 28), 0);
		i++;
	}
	if (!check_duplicate(args->array, args->size))
		return (write(2, "Error\nDuplicated numbers\n", 16), 0);
	return (1);
}
