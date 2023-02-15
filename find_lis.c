/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:31:48 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/15 15:54:05 by mel-aini         ###   ########.fr       */
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
			return (len[i]);
		i++;
	}
	return (len[i]);
}

int	*alloc_lis(t_list *stack, int *len, int *indexes, int size, t_tools	**tools)
{
	int		*lis;
	int		*lis_indexes;
	int		l;
	int		i;
	int		j;
	int		k;

	lis = NULL;
	l = longest_index(len, size);
	(*tools)->lis_size = l;
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
	while (i < size)
	{
		j = 0;
		tmp2 = stack_head;
		while (j < size)
		{
			if (tmp->content > tmp2->content)
				break ;
			j++;
			tmp2 = tmp2->next;
		}
		if (j == size)
		{
			while (i > 0)
			{
				ra(&stack_head, 0);
				i--;
			}
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	return (stack_head);
}

t_list	*put_small_at_top(t_list *stack, int size, int print)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*stack_head;
	int		i;
	int		j;

	stack_head = stack;
	tmp = stack;
	i = 0;
	while (i <= size / 2)
	{
		if (tmp->content > tmp->next->content)
		{
			while (i >= 0)
			{
				ra(&stack_head, print);
				i--;
			}
			return (stack_head);
		}
		tmp = tmp->next;
		i++;
	}
	j = ((size / 2) * -1) + (1 - size % 2);
	while (i < size)
	{
		if (i == size - 1)
		{
			rra(&stack_head, print);
			return (stack_head);
		}
		if (tmp->content > tmp->next->content)
		{
			j++;
			while (j < 0)
			{
				rra(&stack_head, print);
				j++;
			}
			return (stack_head);
		}
		tmp = tmp->next;
		i++;
		j++;
	}
	return (stack_head);
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

int *find_lis(t_list *stack, t_tools *tools)
{
	int		i;
	int		j;
	int		size;
	t_list	*tmp_tmp;
	t_list	*tmp_head;
	t_list	*tmp;
	int		*len;
	int		*indexes;

	size = ft_lstsize(stack);
	tmp = dup_stack(stack, size);
	len = fill_len(size);
	indexes = malloc(sizeof(int) * size);
	indexes[0] = 0;
	tmp_head = tmp;
	tmp_tmp = tmp->next;
	i = 1;
	while (i < size)
	{
		j = 0;
		tmp = tmp_head;
		while (j < i)
		{
			if (tmp->content < tmp_tmp->content)
			{
				if (len[i] <= len[j])
				{
					len[i] = len[j] + 1;
					indexes[i] = j;
				}
			}
			tmp = tmp->next;
			j++;
		}
		tmp_tmp = tmp_tmp->next;
		i++;
	}
	return (alloc_lis(tmp_head, len, indexes, size, &tools));
}
