/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:13:42 by mel-aini          #+#    #+#             */
/*   Updated: 2023/04/28 09:03:40 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	*best_move(t_list *stack_a, t_list *stack_b, t_tools **tools, int size)
{
	int	i;
	int	**pos;
	int	best;

	pos = alloc_pos(size);
	(*tools)->pos = pos;
	i = 0;
	while (i < size)
	{
		if (i <= size / 2)
			pos[i][1] = i;
		else
			pos[i][1] = (size - i) * -1;
		elem_pos_at_a(stack_a, stack_b->content, pos, i);
		stack_b = stack_b->next;
		i++;
	}
	best = minimum_moves(pos, size);
	return (pos[best]);
}

void	repeat_rr(t_list **stack_a, t_list **stack_b, int a, int b)
{
	int	j;

	j = 0;
	while (j < min(a, b))
	{
		rr(&(*stack_a), &(*stack_b), 1);
		j++;
	}
	j = diff(a, b);
	while (j != 0)
	{
		if (j > 0)
		{
			ra(&(*stack_a), 1);
			j--;
		}
		else
		{
			rb(&(*stack_b), 1);
			j++;
		}
	}
}

void	repeat_rrr(t_list **stack_a, t_list **stack_b, int a, int b)
{
	int		j;

	j = 0;
	while (j < min(absolute(a), absolute(b)))
	{
		rrr(&(*stack_a), &(*stack_b), 1);
		j++;
	}
	j = diff(absolute(a), absolute(b));
	while (j != 0)
	{
		if (j > 0)
		{
			rra(&(*stack_a), 1);
			j--;
		}
		else
		{
			rrb(&(*stack_b), 1);
			j++;
		}
	}
}

void	unique_moves(t_list **stack_a, t_list **stack_b, int a, int b)
{
	int	j;

	j = 0;
	while (j < absolute(b))
	{
		if (b > 0)
			rb(&(*stack_b), 1);
		else if (b < 0)
			rrb(&(*stack_b), 1);
		j++;
	}
	j = 0;
	while (j < absolute(a))
	{
		if (a > 0)
			ra(&(*stack_a), 1);
		else if (a < 0)
			rra(&(*stack_a), 1);
		j++;
	}
}

t_list	*iterate_b(t_list *stack_a, t_list **stack_b, t_tools *tools)
{
	int		i;
	int		*best_elem;
	int		size_b;
	t_list	*stack_b_tmp;

	stack_b_tmp = *stack_b;
	size_b = ft_lstsize(stack_b_tmp);
	i = 0;
	while (i < size_b)
	{
		best_elem = best_move(stack_a, stack_b_tmp, &tools, size_b - i);
		if (best_elem[0] > 0 && best_elem[1] > 0)
			repeat_rr(&stack_a, &stack_b_tmp, best_elem[0], best_elem[1]);
		else if (best_elem[0] < 0 && best_elem[1] < 0)
			repeat_rrr(&stack_a, &stack_b_tmp, best_elem[0], best_elem[1]);
		else
			unique_moves(&stack_a, &stack_b_tmp, best_elem[0], best_elem[1]);
		free_pos(&tools, size_b - i);
		pa(&stack_a, &stack_b_tmp, 1);
		i++;
	}
	*stack_b = stack_b_tmp;
	return (stack_a);
}
