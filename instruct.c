/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:13:09 by gpollast          #+#    #+#             */
/*   Updated: 2025/06/27 14:57:40 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

t_stack *swap(t_stack *stack)
{
    int tmp;
    
    if (!stack || !stack->next)
        return stack;
    tmp = stack->content;
    stack->content = stack->next->content;
    stack->next->content = tmp;
    return (stack);
}

t_stack  *p(t_stack *in, t_stack *out)
{
    in = stack_push(in, out->content);
    out = stack_pop(out);
    return (in);
}
