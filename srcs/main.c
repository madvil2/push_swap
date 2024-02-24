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

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (stack)
	{
		current = *stack;
		while (current)
		{
			temp = current->next;
			free(current);
			current = temp;
		}
		*stack = NULL;
	}
}

void	free_on_error(t_stack_node **a, char **arr, bool is_multi_av)
{
	free_stack(a);
	if (is_multi_av)
		free_matrix(arr);
	ft_printf("Error\n");
	exit(1);
}

int	check_is_number(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-' && !(str[1] >= '0' && str[1] <= '9')))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	check_is_duplicate(t_stack_node *a, int number)
{
	if (a)
	{
		while (a)
		{
			if (a->value == number)
				return (1);
			a = a->next;
		}
	}
	return (0);
}

t_stack_node	*my_lstlast(t_stack_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	create_node(t_stack_node **stack, int number)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack)
	{
		node = malloc(sizeof(t_stack_node));
		if (!node)
			return ;
		node->next = NULL;
		node->value = number;
		if (!*stack)
		{
			*stack = node;
			node->prev = NULL;
		}
		else
		{
			last_node = my_lstlast(*stack);
			last_node->next = node;
			node->prev = last_node;
		}
	}
}

void	init_stack(t_stack_node **a, char **arr, bool is_multi_av)
{
	long long int	number;
	int				i;

	i = 0;
	while (arr[i])
	{
		if (check_is_number(arr[i]))
			free_on_error(a, arr, is_multi_av);
		number = ft_atoll(arr[i]);
		if (number > INT_MAX || number < INT_MIN)
			free_on_error(a, arr, is_multi_av);
		if (check_is_duplicate(*a, (int)number))
			free_on_error(a, arr, is_multi_av);
		create_node(a, (int)number);
		i++;
	}
	if (is_multi_av)
		free_matrix(arr);
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

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (1 == ac || (2 == ac && !av[1][0]))
		return (1);
	else if (2 == ac)
		av = ft_split(av[1], ' ');
	init_stack(&a, av, 2 == ac);
	if (!is_stack_sorted(a))
	{
		printf("not sorted");
	}
	return (0);
}
