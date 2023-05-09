/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:52:29 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/08 18:52:29 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	pb(t_list **stack_a, t_list **stack_b, int print)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_a) > 0)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
		if (print)
			write(1, "pb\n", 3);
	}
}
