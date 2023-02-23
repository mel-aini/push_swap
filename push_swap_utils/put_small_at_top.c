/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_small_at_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:32:37 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/23 18:40:59 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

t_list	*rotate_to_top(t_list *stack, int i, int print)
{
	while (i >= 0)
	{
		ra(&stack, print);
		i--;
	}
	return (stack);
}

t_list	*rotate_reverse_to_top(t_list *stack, int i, int size, int print)
{
	while (i < size - 1)
	{
		rra(&stack, print);
		i++;
	}
	return (stack);
}

t_list	*put_small_at_top(t_list *stack, int size, int print)
{
	t_list	*stack_head;
	int		i;

	stack_head = stack;
	i = 0;
	if (check_if_sorted(stack))
		exit(EXIT_SUCCESS);
	while (i < size)
	{
		if (stack->content > stack->next->content)
		{
			if (i <= size / 2)
				stack_head = rotate_to_top(stack_head, i, print);
			else
				stack_head = rotate_reverse_to_top(stack_head, i, size, print);
			return (stack_head);
		}
		stack = stack->next;
		i++;
	}
	return (stack_head);
}