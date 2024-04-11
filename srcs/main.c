/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:12:37 by kokaimov          #+#    #+#             */
/*   Updated: 2024/04/11 20:43:17 by kokaimov         ###   ########.fr       */
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
	while (i < len - 3)
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

static t_stack_node	*find_smallest(t_stack_node *stack)
{
	long	smallest_value;
	t_stack_node	*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest_value = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest_value)
		{
			smallest_value = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
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

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = len_b - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - (b->target_node->current_position);
		b = b->next;
	}
}

static void	set_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long	best_index;

	while (b)
	{
		best_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_index)
			{
				best_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_index)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long	best_value;
	t_stack_node	*best_node;

	if (NULL == b)
		return ;
	best_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_value)
		{
			best_value = b->push_price;
			best_node = b;
		}
		b = b->next;
	}
	best_node->cheapest = true;
}

void	set_position(t_stack_node *stack)
{
	int	i;
	int	center;

	i = 0;
	if (NULL == stack)
		return ;
	center = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= center)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_position(a);
	set_position(b);
	set_target(a, b);
	set_price(a, b);
	set_cheapest(b);
}

static void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b, true);
	set_position(*a);
	set_position(*b);
}

static void	reverse_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b, true);
	set_position(*a);
	set_position(*b);
}

void	finish_rotation(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
		reverse_rotate_both(a, b, cheapest);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest->target_node, 'a');
	pa(a, b, true);
}

void	handle_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(a, b, true);
	}
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int	len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		handle_five(a, b);
	else
		average_divider_sort(a, b);
	drei_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, true);
	else
		while (*a != smallest)
			rra(a, true);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
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
			push_swap(&a, &b);
	}
	free_stack(&a);
}
