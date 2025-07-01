/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:17:42 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/01 20:00:36 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_stack	*stack_push(t_stack *tail, t_stack *element)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->content = element->content;
	head->index = element->index;
	head->next = tail;
	return (head);
}

t_stack	*stack_pop(t_stack *stack)
{
	t_stack	*next;

	if (!stack)
		return (NULL);
	next = stack->next;
	free(stack);
	return (next);
}

void	stack_destroy(t_stack *head)
{
	if (!head)
		return ;
	stack_destroy(head->next);
	free(head);
}

t_stack	*new_stack(int content)
{
	t_stack	*new;

	new = malloc(sizeof(new));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = -1;
	new->next = NULL;
	return (new);
}