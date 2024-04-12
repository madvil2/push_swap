/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:13:09 by kokaimov          #+#    #+#             */
/*   Updated: 2024/04/12 03:59:15 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//utils.c
int				stack_len(t_stack_node *stack);
bool			is_stack_sorted(t_stack_node *stack);
t_stack_node	*my_lstlast(t_stack_node *lst);
void			free_on_error(t_stack_node **a, char **arr, bool is_multi_av);

//stack_init.c 5/5
void			free_stack(t_stack_node **stack);
void			init_stack(t_stack_node **a, char **arr, bool is_multi_av);

//operations_push.c 3/5
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);

//operations_reverse_rotate.c 4/5
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

//operations_rotate.c
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

//operations_swap.c
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

//divider_sort.c 2/5
void			average_divider_sort(t_stack_node **a, t_stack_node **b);

//exceptions.c 4/5
t_stack_node	*find_smallest(t_stack_node *stack);
void			drei_sort(t_stack_node **a);
void			handle_five(t_stack_node **a, t_stack_node **b);

//nodes_init.c 5/5
void			set_position(t_stack_node *stack);
void			init_nodes(t_stack_node *a, t_stack_node *b);

//sort_utils.c 5/5
void			finish_rotation(t_stack_node **stack,
					t_stack_node *top_node, char stack_name);
void			move_nodes(t_stack_node **a, t_stack_node **b);

#endif