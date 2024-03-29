/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_stack_b_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:25:49 by mel-aini          #+#    #+#             */
/*   Updated: 2023/04/28 09:03:06 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	**alloc_pos(int size)
{
	int	i;
	int	**pos;

	pos = malloc(sizeof(int *) * size);
	i = 0;
	while (i < size)
	{
		pos[i] = malloc(sizeof(int) * 2);
		i++;
	}
	return (pos);
}

int	minimum_moves(int **pos, int size)
{
	int	i;
	int	best;

	i = 0;
	best = 0;
	while (++i < size)
	{
		if (max_moves(pos[i][0], pos[i][1])
			< max_moves(pos[best][0], pos[best][1]))
			best = i;
	}
	return (best);
}

int	pos_of_smallest(t_list *stack_a, int size)
{
	int		i;
	t_list	*tmp;

	tmp = stack_a->next;
	i = 0;
	while (i < size && tmp)
	{
		if (stack_a->content > tmp->content)
		{
			if (i <= size / 2)
				return (i + 1);
			return ((size - i - 1) * -1);
		}
		stack_a = stack_a->next;
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	pos_of_largest(t_list *stack_a, int size)
{
	int		i;
	t_list	*tmp;

	tmp = stack_a->next;
	i = 0;
	while (i < size && tmp)
	{
		if (stack_a->content > tmp->content)
		{
			if (i <= size / 2)
				return (i + 1);
			return ((size - i - 1) * -1);
		}
		stack_a = stack_a->next;
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	elem_pos_at_a(t_list *stack_a, int elem, int **pos, int index)
{
	int		i;
	int		size;
	t_list	*stack_a_head;

	size = ft_lstsize(stack_a);
	stack_a_head = stack_a;
	i = -1;
	if (smallest(stack_a, elem, size))
		pos[index][0] = pos_of_smallest(stack_a_head, size);
	else if (biggest(stack_a, elem, size))
		pos[index][0] = pos_of_largest(stack_a_head, size);
	else
	{
		while (++i < size && stack_a->content > elem)
			stack_a = stack_a->next;
		i--;
		while (++i < size && elem > stack_a->content)
			stack_a = stack_a->next;
		if (i <= size / 2)
			pos[index][0] = i;
		else
			pos[index][0] = (size - i) * -1;
	}
}
