/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_nums.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:21:21 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/26 12:14:59 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	smallest(t_list *stack_a, int elem, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (elem > stack_a->content)
			return (0);
		stack_a = stack_a->next;
		i++;
	}
	return (1);
}

int	biggest(t_list *stack_a, int elem, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (elem < stack_a->content)
			return (0);
		stack_a = stack_a->next;
		i++;
	}
	return (1);
}

void	bring_small_to_top(t_list **stack_a, t_list **stack_b, int size, int j)
{
	int	pos;

	if (j <= size / 2)
	{
		pos = j;
		while (pos > 0)
		{
			ra(stack_a, 1);
			pos--;
		}
	}
	else
	{
		pos = (size - j) * -1;
		while (pos < 0)
		{
			rra(stack_a, 1);
			pos++;
		}
	}
	pb(stack_a, stack_b, 1);
}

t_list	*sort_3_nums(t_list *stack_a, int size)
{
	if (size == 2)
		sa(&stack_a, 1);
	else
	{	
		while (!check_if_sorted(stack_a))
		{
			if (stack_a->content < stack_a->next->content
				&& stack_a->next->content > stack_a->next->next->content)
				rra(&stack_a, 1);
			else if (stack_a->content > stack_a->next->content
				&& stack_a->next->content > stack_a->next->next->content)
				ra(&stack_a, 1);
			else if (stack_a->content > stack_a->next->content)
				sa(&stack_a, 1);
			else
				ra(&stack_a, 1);
		}
	}
	return (stack_a);
}

t_list	*sort_5_nums(t_list *stack_a, t_list *stack_b, int size)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = stack_a;
	i = -1;
	while (++i < size - 3)
	{
		j = -1;
		tmp = stack_a;
		while (++j < size - i)
		{
			if (smallest(stack_a, tmp->content, size - i))
			{
				bring_small_to_top(&stack_a, &stack_b, size - i, j);
				break ;
			}
			tmp = tmp->next;
		}
	}
	stack_a = sort_3_nums(stack_a, 3);
	i = -1;
	while (++i < size - 3)
		pa(&stack_a, &stack_b, 1);
	return (stack_a);
}
