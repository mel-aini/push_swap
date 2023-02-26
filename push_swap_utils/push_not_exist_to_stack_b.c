/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_not_exist_to_stack_b.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:36:12 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/26 11:29:32 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	exist(t_tools *tools, int elem)
{
	int	j;

	j = 0;
	while (j < tools->lis_size)
	{
		if (elem == tools->lis[j])
			return (1);
		j++;
	}
	return (0);
}

t_list	*push_not_exist_to_stack_b(t_list **stack_a, t_tools *tools, int size)
{
	t_list	*stack_b;
	t_list	*sa_tmp;
	int		i;

	sa_tmp = *stack_a;
	stack_b = NULL;
	if (size == tools->lis_size)
		return (stack_b);
	i = 0;
	while (i < size)
	{
		if (exist(tools, sa_tmp->content))
			ra(&sa_tmp, 1);
		else
			pb(&sa_tmp, &stack_b, 1);
		i++;
	}
	*stack_a = sa_tmp;
	free(tools->lis);
	return (stack_b);
}
