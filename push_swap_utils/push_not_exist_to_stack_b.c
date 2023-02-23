/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_not_exist_to_stack_b.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:36:12 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/23 18:11:06 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	exist(t_tools *tools, int elem)
{
	int	j;

	j = 0;
	while (j < tools->lis_size)
	{
		if (elem == tools->lis[j])
			return (1);
		j++;
	}
	return (0);
}

int	the_best(t_tools *tools, int size)
{
	int	best;
	int	i;

	i = 0;
	best = i;
	while (++i < size - tools->lis_size)
	{
		if (absolute(tools->pos_b[i]) < absolute(tools->pos_b[best]))
			best = i;
	}
	return (tools->pos_b[best]);
}

int	find_best_move(t_list *stack, t_tools *tools, int size)
{
	int	i;
	int	j;

	tools->pos_b = malloc(sizeof(int) * size - tools->lis_size);
	if (!tools->pos_b)
		exit(EXIT_FAILURE);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (!exist(tools, stack->content))
		{
			if (i <= size / 2)
				tools->pos_b[j] = i;
			else
				tools->pos_b[j] = (size - i) * -1;
			j++;
		}
		stack = stack->next;
		i++;
	}
	return (the_best(tools, size));
}

t_list	*repeat_rotate(t_list *stack, int limit, int rotate)
{
	int	j;

	j = 0;
	while (j < limit)
	{
		if (rotate == 1)
			ra(&stack, 1);
		else if (rotate == 2)
			rra(&stack, 1);
		j++;
	}
	return (stack);
}

t_list	*push_not_exist_to_stack_b(t_list **stack_a, t_tools *tools, int size)
{
	t_list	*stack_b;
	t_list 	*sa_tmp;
	int		i;
	int		best;

	sa_tmp = *stack_a;
	stack_b = NULL;
	if (size == tools->lis_size)
		return (stack_b);
	i = 0;
	while (i < size - tools->lis_size)
	{
		best = find_best_move(sa_tmp, tools, size - i);
		if (best > 0)
			sa_tmp = repeat_rotate(sa_tmp, best, 1);
		else if (best < 0)
			sa_tmp = repeat_rotate(sa_tmp, absolute(best), 2);
		free(tools->pos_b);
		tools->pos_b = NULL;
		pb(&sa_tmp, &stack_b);
		i++;
	}
	*stack_a = sa_tmp;
	return (stack_b);
}