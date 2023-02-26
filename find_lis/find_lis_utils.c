/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:19:24 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/24 19:01:07 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_lis.h"

int	*fill_len(int size)
{
	int	*len;
	int	i;

	len = malloc(sizeof(int) * size);
	if (!len)
		ft_error();
	i = 0;
	while (i < size)
	{
		len[i] = 1;
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
				break ;
			j++;
		}
		if (j == size)
			return (len[i]);
		i++;
	}
	return (len[i]);
}

void	free_all_lis_tools(t_tools *tools)
{
	free(tools->indexes);
	free(tools->len);
	free(tools->lis_indexes);
}

void	alloc_lis_indexes(t_tools *tools, int size)
{
	int	i;
	int	j;
	int	k;

	tools->lis_indexes = malloc(sizeof(int) * tools->lis_size);
	if (!tools->lis_indexes)
		ft_error();
	i = 0;
	while (i < size && tools->len[i] != tools->lis_size)
		i++;
	tools->lis_indexes[tools->lis_size - 1] = i;
	j = i;
	k = tools->lis_size - 2;
	while (i >= 0)
	{
		if (tools->indexes[j] == i)
		{
			tools->lis_indexes[k] = i;
			k--;
			j = i;
		}
		i--;
	}
}

void	alloc_lis(t_list *stack, t_tools *tools, int size)
{
	int		i;
	int		j;

	tools->lis = NULL;
	tools->lis = malloc(sizeof(int) * tools->lis_size);
	if (!tools->lis)
		ft_error();
	alloc_lis_indexes(tools, size);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (i == tools->lis_indexes[j])
		{
			tools->lis[j] = stack->content;
			j++;
		}
		stack = stack->next;
		i++;
	}
	free_all_lis_tools(tools);
}
