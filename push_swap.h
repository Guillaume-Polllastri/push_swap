/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:40:17 by gpollast          #+#    #+#             */
/*   Updated: 2025/07/13 19:27:57 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STR_MAX_INT "2147483647"
# define STR_MIN_INT "2147483648"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info_stack
{
	int	max;
	int	min;
	int	pos;
}	t_info_stack;

typedef struct s_args
{
	char	**array;
	int		size;
}	t_args;

/* ************************************************************************** */

int				ft_stacksize(t_stack *stack);
t_stack			*ft_stacklast(t_stack *stack);
t_stack			*stack_push(t_stack *tail, t_stack *element);
void			stack_destroy(t_stack *head);
t_stack			*new_stack(int content);
t_stack			*stack_pop(t_stack *stack);
void			free_stacks(t_stack **stack);
void			free_string_array(char **array);
double			sqrt(double nb);
char			**string_array_concat(char **split1, char **split2);
int				parse_args(t_args *args, int ac, char **av);
int				validate_args(t_args *args);
int				fill_stack(t_stack **a, t_args *args);
int				is_sort_stack(t_stack *stack);

/* ************************************************************************** */

t_stack			*swap(t_stack *stack);
void			push_elem(t_stack **in, t_stack **out);
void			rotate(t_stack **stack);
void			reverse_rotate(t_stack **stack);

/* ************************************************************************** */

void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);

/* ************************************************************************** */

int				cond_sort(t_stack **a, t_stack **b, int nb_elmt);
void			fill_stack_index(t_stack **a, int *tab, int nb_elmt);
int				*fill_tab(t_stack **a, int nb_elmt);
int				k_sort(t_stack **a, t_stack **b, int nb_elmt);
int				index_element(int *tab, int element, int nb_elmt);
t_info_stack	where_is_max_index(t_stack *stack);

/* ************************************************************************** */

int				check_instructions(t_stack **a, t_stack **b, char *line);

#endif