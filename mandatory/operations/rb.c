/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:17:19 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/09 00:17:19 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rb(t_list **stack_b, int print)
{
	t_list	*tmp;
	t_list	*ptr;

	ptr = *stack_b;
	tmp = ft_lstnew((*stack_b)->content);
	*stack_b = (*stack_b)->next;
	free(ptr);
	ptr = *stack_b;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = tmp;
	if (print)
		write(1, "rb\n", 3);
}
