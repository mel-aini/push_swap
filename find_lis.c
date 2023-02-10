/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:31:48 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/09 17:43:08 by mel-aini         ###   ########.fr       */
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

int	longest_index(t_list *len, int size)
{
	int		i;
	int		j;
	t_list	*len_head;
	t_list	*len_tmp;

	i = 0;
	len_head = len;
	while (i < size)
	{
		j = 0;
		len_tmp = len_head;
		while (j < size)
		{
			if (len->content < len_tmp->content)
				break;
			len_tmp = len_tmp->next;
			j++;
		}
		if (j == size)
			return (len->content);
		len = len->next;
		i++;
	}
	return (len->content);
}

int	*alloc_lis(t_list *stack, t_list *len, int *indexes, int size)
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
	while (i < size && len->content != l)
	{
		len = len->next;
		i++;
	}
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
			// printf("Here\n");
			// printf("at j = %d => %d\n", j, lis[j]);
			lis[j] = stack->content;
			j++;
		}
		stack = stack->next;
		i++;	
	}
	return (lis);
}

int *find_lis(t_list *stack)
{
    int		i;
    int		j;
    int		size;
	t_list	*stack_tmp;
	t_list	*stack_head;
	t_list	*len;
	t_list	*len_tmp;
	t_list	*len_head;
	int		*indexes;

	size = ft_lstsize(stack);
	len = new_list(size, 1);
	indexes = malloc(sizeof(int) * size);
	indexes[0] = 0;
	stack_head = stack;
	len_head = len;
	stack_tmp = stack->next;
	len_tmp = len->next;
	i = 1;
	while (i < size)
	{
		j = 0;
		len = len_head;
		stack = stack_head;
		while (j < i)
		{
			if (stack->content < stack_tmp->content)
			{
				if (len_tmp->content <= len->content)
				{
					len_tmp->content = len->content + 1;
					indexes[i] = j;
				}
			}
			stack = stack->next;
			len = len->next;
			j++;
		}
		stack_tmp = stack_tmp->next;
		len_tmp = len_tmp->next;
		i++;
	}
	int *lis = alloc_lis(stack_head, len_head, indexes, size);
	return (lis);
}
