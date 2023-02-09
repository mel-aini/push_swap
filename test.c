/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:36:37 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/08 14:36:37 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
    t_list *stack_a;
    t_list *stack_b;

    stack_a = ft_lstnew(1);
    ft_lstadd_back(&stack_a, ft_lstnew(2));
    ft_lstadd_back(&stack_a, ft_lstnew(3));

    stack_b = ft_lstnew(11);
    ft_lstadd_back(&stack_b, ft_lstnew(12));
    ft_lstadd_back(&stack_b, ft_lstnew(13));

    rra(&stack_a);

    while (stack_a->next != NULL)
    {
        printf("%d\n", stack_a->content);
        stack_a = stack_a->next;
        if (stack_a->next == NULL)
            printf("%d\n", stack_a->content);
    }
}

// 70/65