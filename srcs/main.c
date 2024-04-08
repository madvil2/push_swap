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
		printf("not sorted");
	}
	else
		printf("Sorted");
	return (0);
}
