/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:31:48 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/11 11:15:47 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_list(int n, int content)
{
	t_list	*len;
	int		i;

	if (!n)
		return (0);
	len = ft_lstnew(content);
	i = 1;
	while (i < n)
	{
		ft_lstadd_back(&len, ft_lstnew(1));
		i++;
	}
	return (len);
}

int	longest_index(int *len, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (len[i] < len[j])
				break;
			j++;
		}
		if (j == size)
			return (len[j - 1]);
		i++;
	}
	return (len[j]);
}

int	*alloc_lis(t_list *stack, int *len, int *indexes, int size)
{
	int		*lis;
	int		*lis_indexes;
	int		l;
	int		i;
	int		j;
	int		k;

	lis = NULL;
	l = longest_index(len, size);
	lis_indexes = malloc(sizeof(int) * l);
	lis = malloc(sizeof(int) * l);
	i = 0;
	while (i < size && len[i] != l)
		i++;
	lis_indexes[l - 1] = i;
	j = i;
	k = l - 2;
	while (i >= 0)
	{
		if (indexes[j] == i)
		{
			lis_indexes[k] = i;
			k--;
			j = i;
		}
		i--;
	}
	i = 0;
	j = 0;
	while (i < size)
	{
		if (i == lis_indexes[j])
		{
			lis[j] = stack->content;
			j++;
		}
		stack = stack->next;
		i++;	
	}
	free(indexes);
	free(len);
	free(lis_indexes);
	return (lis);
}

int	*fill_len(int size)
{
	int	*len;
	int	i;

	len = malloc(sizeof(int) * size);
	if (!len)
		return (NULL);
	i = 0;
	while (i < size)
	{
		len[i] = 1;
		i++;
	}
	return (len);
}

int *find_lis(t_list *stack)
{
	int		i;
	int		j;
	int		size;
	t_list	*stack_tmp;
	t_list	*stack_head;
	int		*len;
	int		*indexes;
	
	size = ft_lstsize(stack);
	len = fill_len(size);
	indexes = malloc(sizeof(int) * size);
	indexes[0] = 0;
	stack_head = stack;
	stack_tmp = stack->next;
	i = 1;
	while (i < size)
	{
		j = 0;
		stack = stack_head;
		while (j < i)
		{
			if (stack->content < stack_tmp->content)
			{
				if (len[i] <= len[j])
				{
					len[i] = len[j] + 1;
					indexes[i] = j;
				}
			}
			stack = stack->next;
			j++;
		}
		stack_tmp = stack_tmp->next;
		i++;
	}
	return (alloc_lis(stack_head, len, indexes, size));
}
