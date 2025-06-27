/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:40:17 by gpollast          #+#    #+#             */
/*   Updated: 2025/06/27 14:40:42 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_push(t_stack *tail, int content);
void	stack_destroy(t_stack *head);
t_stack	*stack_pop(t_stack *stack);
t_stack	*swap(t_stack *stack);
t_stack	*p(t_stack *in, t_stack *out);
#endif