/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 22:33:26 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/26 22:33:26 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		stack_len(t_stack_node *stack)
{
	int	count;

	if (stack)
	{
		count = 0;
		while (stack)
		{
			count++;
			stack = stack->next;
		}
		return (count);
	}
	return (0);
}

bool	is_stack_sorted(t_stack_node *stack)
{
	if (stack)
	{
		while (stack->next)
		{
			if (stack->value > stack->next->value)
				return (false);
			stack = stack->next;
		}
	}
	return (true);
}

void	free_on_error(t_stack_node **a, char **arr, bool is_multi_av)
{
	free_stack(a);
	if (is_multi_av)
		free_matrix(arr);
	ft_printf("Error\n");
	exit(1);
}

t_stack_node	*my_lstlast(t_stack_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
