/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divider_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 03:40:47 by kokaimov          #+#    #+#             */
/*   Updated: 2024/04/12 03:41:13 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	calculate_average(t_stack_node *stack)
{
	int	sum;
	int	count;

	if (stack == NULL)
		return (0);
	sum = 0;
	count = 0;
	while (stack)
	{
		sum += stack->value;
		count++;
		stack = stack->next;
	}
	return (sum / count);
}

void	average_divider_sort(t_stack_node **a, t_stack_node **b)
{
	int	average;
	int	len;

	len = stack_len(*a);
	average = calculate_average(*a);
	while (len != 3)
	{
		if ((*a)->value < average)
		{
			pb(a, b);
			rb(b);
			average = calculate_average(*a);
			len = stack_len(*a);
		}
		else
			ra(a);
	}
}
