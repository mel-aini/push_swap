/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:08:57 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/09 00:08:57 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void    ra(t_list **stack_a)
{
	t_list *tmp;
	t_list	*ptr;
	
	ptr = *stack_a;
	tmp = ft_lstnew((*stack_a)->content);
	*stack_a = (*stack_a)->next;
	free(ptr);
	ptr = *stack_a;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = tmp;
}