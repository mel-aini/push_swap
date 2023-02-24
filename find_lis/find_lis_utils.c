/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:14:23 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/24 10:55:43 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_lis.h"

t_list	*rotate_stack(t_list *stack_head, int i, int limit)
{
	while (i > limit)
	{
		ra(&stack_head, 0);
		i--;
	}
	return (stack_head);
}

t_list	*put_small_of_tmp_at_top(t_list *stack, int size)
{
	t_list	*tmp;
	t_list	*stack_head;
	int		i;

	stack_head = stack;
	tmp = stack;
	i = 0;
	while (i < size)
	{
		if (smallest(stack, tmp->content, size))
		{
			stack_head = rotate_stack(stack_head, i, 0);
			break ;
		}
		i++;
		tmp = tmp->next;
	}
	return (stack_head);
}

t_list	*put_max_of_tmp_at_bottom(t_list *stack, int size)
{
	t_list	*tmp;
	t_list	*stack_head;
	int		i;

	stack_head = stack;
	tmp = stack;
	i = 0;
	while (i < size)
	{
		if (biggest(stack, tmp->content, size))
		{
			stack_head = rotate_stack(stack_head, i, -1);
			break ;
		}
		i++;
		tmp = tmp->next;
	}
	return (stack_head);
}

void	init_tools(t_tools *tools, t_list *stack, int size)
{
	tools->tmp_stack = malloc(sizeof(t_list *) * 3);
	if (!tools->tmp_stack)
		ft_error();
	tools->tmp_stack[0] = stack;
	tools->tmp_stack[1] = dup_stack(stack, size);
	tools->tmp_stack[2] = dup_stack_2(stack, size);
	tools->len = malloc(sizeof(int *) * 3);
	tools->indexes = malloc(sizeof(int *) * 3);
	tools->stack_size = size;
	if (!tools->len || !tools->len)
		ft_error();
}
