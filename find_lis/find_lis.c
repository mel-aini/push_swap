/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:31:48 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/24 18:45:13 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_lis.h"

// void	free_stack(t_list *stack)
// {
// 	int		i;
// 	int		size;
// 	t_list	*tmp;

// 	size = ft_lstsize(stack);
// 	tmp = stack;
// 	i = 0;
// 	while (i < size)
// 	{
// 		tmp = stack;
// 		stack = stack->next;
// 		free(tmp);
// 		i++;
// 	}
// }

void	find_longest_lis(t_tools *tools, int size)
{
	int		i;
	int		*tmp_lis;

	tmp_lis = malloc(sizeof(int) * 3);
	if (!tmp_lis)
		ft_error();
	i = -1;
	while (++i < 3)
		tmp_lis[i] = longest_index(tools->len[i], size);
	i = 1;
	tools->best_lis = tools->tmp_stack[0];
	tools->lis_size = tmp_lis[0];
	tools->index = 0;
	while (i < 3)
	{
		if (tmp_lis[i] > tmp_lis[i - 1])
		{
			tools->best_lis = tools->tmp_stack[i];
			tools->lis_size = tmp_lis[i];
			tools->index = i;
		}
		i++;
	}
	free(tmp_lis);
}

t_list	*dup_stack(t_list *stack, int size)
{
	t_list	*dup;
	int		i;

	dup = NULL;
	i = 0;
	while (i < size)
	{
		ft_lstadd_back(&dup, ft_lstnew(stack->content));
		stack = stack->next;
		i++;
	}
	dup = put_small_of_tmp_at_top(dup, size);
	return (dup);
}

t_list	*dup_stack_2(t_list *stack, int size)
{
	t_list	*dup;
	int		i;

	dup = NULL;
	i = 0;
	while (i < size)
	{
		ft_lstadd_back(&dup, ft_lstnew(stack->content));
		stack = stack->next;
		i++;
	}
	dup = put_max_of_tmp_at_bottom(dup, size);
	return (dup);
}

void	alloc_elems(t_tools *tools, int index, t_list *tmp2)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 1;
	while (i < tools->stack_size)
	{
		j = 0;
		tmp = tools->tmp_stack[index];
		while (j < i)
		{
			if (tmp->content < tmp2->content)
			{
				if (tools->len[index][i] <= tools->len[index][j])
				{
					tools->len[index][i] = tools->len[index][j] + 1;
					tools->indexes[index][i] = j;
				}
			}
			tmp = tmp->next;
			j++;
		}
		tmp2 = tmp2->next;
		i++;
	}
}

void	find_lis(t_list *stack, t_tools *tools, int size)
{
	int		i;
	t_list	*tmp2;

	init_tools(tools, stack, size);
	i = 0;
	while (i < 3)
	{
		tmp2 = tools->tmp_stack[i]->next;
		tools->len[i] = fill_len(size);
		tools->indexes[i] = malloc(sizeof(int) * size);
		if (!tools->indexes[i])
			ft_error();
		tools->indexes[i][0] = 0;
		alloc_elems(tools, i, tmp2);
		i++;
	}
	find_longest_lis(tools, size);
	alloc_lis(tools, size, tools->index);
}
