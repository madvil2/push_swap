/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:12:37 by kokaimov          #+#    #+#             */
/*   Updated: 2024/02/23 20:54:06 by kokaimov         ###   ########.fr       */
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
	int	i;

	len = stack_len(*a);
	i = 0;
	average = calculate_average(*a);
	while (i < len)
	{
		if ((*a)->value < average)
		{
			pb(a, b, true);
			rb(b, true);
			average = calculate_average(*a);
		}
		else
			ra(a, true);
		i++;
	}
}

static t_stack_node	*find_highest(t_stack_node *stack)
{
	int	highest_value;
	t_stack_node	*highest_node;
	if (NULL == stack)
		return (NULL);
	highest_value = INT_MIN;
	while (stack)
	{
		if (stack->value > highest_value)
		{
			highest_value = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	drei_sort(t_stack_node **a)
{
	t_stack_node	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		ra(a, true);
	else if ((*a)->next == highest)
		rra(a, true);
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}

int	calculate_push_price(t_stack_node **b)
{
	t_stack_node *current = *b;
	int	index;
	int	total_rotation;
	int	stack_len_b;

	index = 0;
	total_rotation = 0;
	stack_len_b = stack_len(*b);
	while (current)
	{
		total_rotation = index;
		if (total_rotation > stack_len_b / 2)
			total_rotation = stack_len_b - index;
		current->push_price = total_rotation;
	}
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
//	t_stack_node	*b;

	a = NULL;
//	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&a, av, ac == 2);
	if (!is_stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, true);
		else if (stack_len(a) == 3)
			drei_sort(&a);
		else
			printf("not sorted");
	}
	else
		printf("Sorted");
	return (0);
}
