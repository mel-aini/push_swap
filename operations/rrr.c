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

void    rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*new;
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
	}
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
	}
	printf("rrr\n");
}