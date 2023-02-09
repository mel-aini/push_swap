/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:41:28 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/08 18:41:28 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void    pa(t_list **stack_a, t_list **stack_b)
{
    t_list  *tmp;
    t_list  *new;

    if (ft_lstsize(*stack_b) > 0)
    {
        new = ft_lstnew((*stack_b)->content);
	    new->next = *stack_a;
	    *stack_a = new;
        // delete node in stack b
        tmp = *stack_b;
        *stack_b = (*stack_b)->next;
        free(tmp);
        tmp = NULL;
    }
}
