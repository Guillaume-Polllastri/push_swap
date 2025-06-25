/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:17:42 by gpollast          #+#    #+#             */
/*   Updated: 2025/06/25 20:58:25 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_stack	*stack_push(t_stack *tail, int content)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = tail;
	return (head);
}

void	stack_destroy(t_stack *head)
{
	if (!head)
		return ;
	stack_destroy(head->next);
	free(head);
}
