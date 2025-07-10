/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:15:07 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/10 14:16:15 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

static int	count_array_elements(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

static void	copy_array_elements(char **dest, char **src, int start_index)
{
	int	i;
	int	j;

	i = start_index;
	j = 0;
	while (src[j])
	{
		dest[i] = ft_strdup(src[j]);
		i++;
		j++;
	}
}

char	**string_array_concat(char **split1, char **split2)
{
	char	**res;
	int		len1;
	int		len2;
	int		total_len;

	len1 = count_array_elements(split1);
	len2 = count_array_elements(split2);
	total_len = len1 + len2;
	res = malloc(sizeof(char *) * (total_len + 1));
	if (!res)
		return (NULL);
	copy_array_elements(res, split1, 0);
	copy_array_elements(res, split2, len1);
	res[total_len] = NULL;
	return (res);
}
