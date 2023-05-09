/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:53:01 by mel-aini          #+#    #+#             */
/*   Updated: 2023/04/28 09:25:04 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_list *stack, int size)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (i < size)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
		tmp = NULL;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_tools	tools;
	int		size_a;

	stack_a = parsing(argc, argv);
	size_a = ft_lstsize(stack_a);
	if (size_a <= 3)
		stack_a = sort_3_nums(stack_a, size_a);
	else if (size_a <= 5)
		stack_a = sort_5_nums(stack_a, NULL, size_a);
	else
	{
		find_lis(stack_a, &tools, size_a);
		stack_b = push_not_exist_to_stack_b(&stack_a, &tools, size_a);
		stack_a = iterate_b(stack_a, &stack_b, &tools);
		stack_a = put_small_at_top(stack_a, ft_lstsize(stack_a), 1);
	}
	free_stack(stack_a, size_a);
	return (0);
}
