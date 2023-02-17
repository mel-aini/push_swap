/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:46:02 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/08 14:46:02 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void    ss(t_list **stack_a, t_list **stack_b)
{
    int tmp;

    if (ft_lstsize(*stack_a) > 1)
    {
        tmp = (*stack_a)->content;
        (*stack_a)->content = (*stack_a)->next->content;
        (*stack_a)->next->content = tmp;
    }
    if (ft_lstsize(*stack_b) > 1)
    {
        tmp = (*stack_b)->content;
        (*stack_b)->content = (*stack_b)->next->content;
        (*stack_b)->next->content = tmp;
    }
    // t_list *stack_a_tmp;
    // t_list *stack_b_tmp;

    // stack_a_tmp = *stack_a;
    // stack_a_tmp = *stack_b;
    // sa(&stack_a_tmp);
    //sb(&stack_b_tmp);
}