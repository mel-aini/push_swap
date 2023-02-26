/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:32:37 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/09 00:32:37 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rra(t_list **stack_a, int print)
{
	t_list	*tmp;
	t_list	*ptr;
	int		i;
	int		size;

	size = ft_lstsize(*stack_a);
	if (size > 1)
	{
		ptr = *stack_a;
		i = 1;
		while (ptr->next != NULL)
		{
			if (i == size - 1)
				tmp = ptr;
			ptr = ptr->next;
			i++;
		}
		ptr->next = *stack_a;
		*stack_a = ptr;
		tmp->next = NULL;
		if (print)
			printf("rra\n");
	}
}
