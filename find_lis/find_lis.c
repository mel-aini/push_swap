/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:31:48 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/24 19:09:16 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_lis.h"

void	alloc_elems(t_list *stack, t_tools *tools, t_list *tmp2)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 1;
	while (i < tools->stack_size)
	{
		j = 0;
		tmp = stack;
		while (j < i)
		{
			if (tmp->content < tmp2->content)
			{
				if (tools->len[i] <= tools->len[j])
				{
					tools->len[i] = tools->len[j] + 1;
					tools->indexes[i] = j;
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
	t_list	*tmp2;

	tmp2 = stack->next;
	tools->stack_size = size;
	tools->len = fill_len(size);
	tools->indexes = malloc(sizeof(int) * size);
	if (!tools->indexes)
		ft_error();
	tools->indexes[0] = 0;
	alloc_elems(stack, tools, tmp2);
	tools->lis_size = longest_index(tools->len, size);
	alloc_lis(stack, tools, size);
}
