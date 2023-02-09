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

t_list	*new_list(int n)
{
	t_list	*len;
	int		i;

	if (!n)
		return (0);
	len = ft_lstnew(1);
	i = 1;
	while (i < n)
	{
		ft_lstadd_back(&len, ft_lstnew(1));
		i++;
	}
	return (len);
}

// int	longest_index(int *arr, int n)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < n)
// 	{
// 		j = 0;
// 		while (j < n)
// 		{
// 			if (arr[i] < arr[j])
// 				break;
// 			j++;
// 		}
// 		if (j == n)
// 			return (i);
// 		i++;
// 	}
// 	return (i);
// }
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

int lis(t_list *stack)
{
    int		i;
    int		j;
    int		size;
	t_list	*stack_tmp;
	t_list	*stack_head;
	t_list	*len;
	t_list	*len_tmp;
	t_list	*len_head;

	size = ft_lstsize(stack);
	len = new_list(size);
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
					len_tmp->content = len->content + 1;
			}
			stack = stack->next;
			len = len->next;
			j++;
		}
		stack_tmp = stack_tmp->next;
		len_tmp = len_tmp->next;
		i++;
	}
	return (longest_index(len_head, size));
}
