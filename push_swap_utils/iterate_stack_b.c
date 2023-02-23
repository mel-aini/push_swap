/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:13:42 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/23 18:43:53 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	*best_to_push_to_a(t_list *stack_a, t_list *stack_b, t_tools **tools)
{
	int	i;
	int	j;
	int	**pos;
	int	best;

	(*tools)->sb_size = ft_lstsize(stack_b);
	pos = alloc_pos((*tools)->sb_size);
	(*tools)->pos = pos;
	i = 0;
	while (i <= (*tools)->sb_size / 2)
	{
		pos[i][1] = i;
		elem_pos_at_a(stack_a, stack_b->content, pos, i);
		stack_b = stack_b->next;
		i++;
	}
	j = (((*tools)->sb_size / 2) * -1) + (1 - (*tools)->sb_size % 2);
	while (i < (*tools)->sb_size)
	{
		pos[i][1] = j;
		elem_pos_at_a(stack_a, stack_b->content, pos, i);
		stack_b = stack_b->next;
		i++;
		j++;
	}
	i = 0;
	best = 0;
	while (++i < (*tools)->sb_size)
	{
		if (max_moves(pos[i][0], pos[i][1]) < max_moves(pos[best][0], pos[best][1]))
			best = i;
	}
	return (pos[best]);
}

void	repeat_rr(t_list **stack_a, t_list **stack_b, int a, int b)
{
	int	j;
	t_list	*sb_tmp;
	t_list	*sa_tmp;

	sa_tmp = *stack_a;
	sb_tmp = *stack_b;
	j = -1;
	while (++j < min(a, b))
		rr(&sa_tmp, &sb_tmp);
	j = diff(a, b);
	while (j != 0)
	{
		if (j > 0)
		{
			ra(&sa_tmp, 1);
			j--;
		}
		else
		{
			rb(&sb_tmp);
			j++;
		}
	}
	*stack_a = sa_tmp;
	*stack_b = sb_tmp;
}

void	repeat_rrr(t_list **stack_a, t_list **stack_b, int a, int b)
{
	t_list	*sb_tmp;
	t_list	*sa_tmp;
	int		j;

	sa_tmp = *stack_a;
	sb_tmp = *stack_b;
	j = -1;
	while (++j < min(absolute(a), absolute(b)))
		rrr(&sa_tmp, &sb_tmp);
	j = diff(absolute(a), absolute(b));
	while (j != 0)
	{
		if (j > 0)
		{
			rra(&sa_tmp, 1);
			j--;
		}
		else
		{
			rrb(&sb_tmp);
			j++;
		}
	}
	*stack_a = sa_tmp;
	*stack_b = sb_tmp;
}

t_list	*iterate_b(t_list *stack_a, t_list **stack_b, t_tools *tools)
{
	int		*best_elem;
	int		i;
	int		j;
	int		size_b;
	t_list	*stack_b_tmp;

	stack_b_tmp = *stack_b;
	size_b = ft_lstsize(stack_b_tmp);
	i = 0;
	while (i < size_b)
	{
		best_elem = best_to_push_to_a(stack_a, stack_b_tmp, &tools);
		if (best_elem[0] > 0 && best_elem[1] > 0)
			repeat_rr(&stack_a, &stack_b_tmp, best_elem[0], best_elem[1]);
		else if (best_elem[0] < 0 && best_elem[1] < 0)
			repeat_rrr(&stack_a, &stack_b_tmp, best_elem[0], best_elem[1]);
		else
		{
			j = 0;
			while (j < absolute(best_elem[1]))
			{
				if (best_elem[1] > 0)
					rb(&stack_b_tmp);
				else if (best_elem[1] < 0)
					rrb(&stack_b_tmp);
				j++;
			}
			j = 0;
			while (j < absolute(best_elem[0]))
			{
				if (best_elem[0] > 0)
					ra(&stack_a, 1);
				else if (best_elem[0] < 0)
					rra(&stack_a, 1);
				j++;
			}
		}
		free_pos(&tools);
		pa(&stack_a, &stack_b_tmp);
		i++;
	}
	*stack_b = stack_b_tmp;
	return (stack_a);
}