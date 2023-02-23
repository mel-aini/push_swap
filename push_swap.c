/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:53:01 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/23 18:32:15 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks()
{
	system("leaks push_swap");
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_tools	tools;
	int		size_a;

	// atexit(leaks);
	stack_a = parsing(argc, argv);
	size_a = ft_lstsize(stack_a);
	if (size_a == 3)
		sort_3_nums(stack_a);
	else if (size_a == 5)
		sort_5_nums(stack_a, NULL, 5);
	else
	{
		find_lis(stack_a, &tools, size_a);
		stack_b = push_not_exist_to_stack_b(&stack_a, &tools, size_a);
		stack_a = iterate_b(stack_a, &stack_b, &tools);
		stack_a = put_small_at_top(stack_a, ft_lstsize(stack_a), 1);
	}
	// system("leaks push_swap");
	return (0);
}