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

void	sa(t_list **stack_a, int print)
{
	int	tmp;

	if (ft_lstsize(*stack_a) > 1)
	{
		tmp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = tmp;
		if (print)
			printf("sa\n");
	}
}
