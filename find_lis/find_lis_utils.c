/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:14:23 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/23 16:00:17 by mel-aini         ###   ########.fr       */
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
	t_list	*tmp2;
	t_list	*stack_head;
	int		i;
	int		j;

	stack_head = stack;
	tmp = stack;
	i = 0;
	while (++i < size)
	{
		j = -1;
		tmp2 = stack_head;
		while (++j < size && tmp->content < tmp2->content)
			tmp2 = tmp2->next;
		if (j == size)
		{
			stack_head = rotate_stack(stack_head, i, 0);
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	return (stack_head);
}

t_list	*put_max_of_tmp_at_bottom(t_list *stack, int size)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*stack_head;
	int		i;
	int		j;

	stack_head = stack;
	tmp = stack;
	i = 0;
	while (i < size)
	{
		j = -1;
		tmp2 = stack_head;
		while (++j < size && tmp->content < tmp2->content)
			tmp2 = tmp2->next;
		if (j == size)
		{
			stack_head = rotate_stack(stack_head, i, -1);
			break ;
		}
		tmp = tmp->next;
		i++;
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
