/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:24:52 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/09 00:24:52 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void    rr(t_list **stack_a, t_list **stack_b)
{
    t_list	*tmp;
    t_list	*ptr;

    // ra
	ptr = *stack_a;
	tmp = ft_lstnew((*stack_a)->content);
	*stack_a = (*stack_a)->next;
	free(ptr);
	ptr = *stack_a;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = tmp;
    // rb
	ptr = *stack_b;
	tmp = ft_lstnew((*stack_b)->content);
	*stack_b = (*stack_b)->next;
	free(ptr);
	ptr = *stack_b;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = tmp;
}