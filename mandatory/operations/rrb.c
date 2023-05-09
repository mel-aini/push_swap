/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:45:48 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/09 00:45:48 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rrb(t_list **stack_b, int print)
{
	t_list	*tmp;
	t_list	*ptr;
	int		i;
	int		size;

	size = ft_lstsize(*stack_b);
	if (size > 1)
	{
		ptr = *stack_b;
		i = 1;
		while (ptr->next != NULL)
		{
			if (i == size - 1)
				tmp = ptr;
			ptr = ptr->next;
			i++;
		}
		ptr->next = *stack_b;
		*stack_b = ptr;
		tmp->next = NULL;
		if (print)
			write(1, "rrb\n", 4);
	}
}
