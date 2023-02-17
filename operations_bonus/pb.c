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

void    pb(t_list **stack_a, t_list **stack_b)
{
    t_list  *tmp;
    t_list  *new;

	// printf("Here\n");
    if (ft_lstsize(*stack_a) > 0)
    {
        new = ft_lstnew((*stack_a)->content);
		// printf("in pb : %d\n", (*stack_a)->content);
	    new->next = *stack_b;
	    *stack_b = new;
        // delete node in stack a
        tmp = *stack_a;
        *stack_a = (*stack_a)->next;
        free(tmp);
        tmp = NULL;
    }
}
