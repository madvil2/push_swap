/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:13:09 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/23 15:13:09 by kokaimov         ###   ########.fr       */
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
	int					current_position; // current_index
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//utils.c
int		stack_len(t_stack_node *stack);
bool	is_stack_sorted(t_stack_node *stack);
t_stack_node	*my_lstlast(t_stack_node *lst);
void	free_on_error(t_stack_node **a, char **arr, bool is_multi_av);

//stack_init.c
void	free_stack(t_stack_node **stack);
void	create_node(t_stack_node **stack, int number);
void	init_stack(t_stack_node **a, char **arr, bool is_multi_av);

//operations_push.c
void	pa(t_stack_node **a, t_stack_node **b, bool to_print);
void	pb(t_stack_node **a, t_stack_node **b, bool to_print);

//operations_reverse_rotate.c
void	rra(t_stack_node **a, bool to_print);
void	rrb(t_stack_node **b, bool to_print);
void	rrr(t_stack_node **a, t_stack_node **b, bool to_print);

//operations_rotate.c
void	ra(t_stack_node **a, bool to_print);
void	rb(t_stack_node **b, bool to_print);
void	rr(t_stack_node **a, t_stack_node **b, bool to_print);

//operations_swap.c
void	sa(t_stack_node **a, bool to_print);
void	sb(t_stack_node **b, bool to_print);
void	ss(t_stack_node **a, t_stack_node **b, bool to_print);

#endif