/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:21:59 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/24 09:18:43 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

int	max_moves(int a, int b)
{
	if (a < 0 && b < 0)
		return (min(absolute(a), absolute(b))
			+ absolute(absolute(a) - absolute(b)));
	else if (a > 0 && b > 0)
		return (min(a, b) + absolute(a - b));
	else
		return (absolute(a) + absolute(b));
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
	return (0);
}

int	diff(int a, int b)
{
	return (a - b);
}

int	absolute(int n)
{
	if (n > 0)
		return (n);
	else if (n < 0)
		return (n * -1);
	return (0);
}

void	free_pos(t_tools **tools, int size_b)
{
	int	i;

	i = 0;
	while (i < size_b)
	{
		free((*tools)->pos[i]);
		(*tools)->pos[i] = NULL;
		i++;
	}
	free((*tools)->pos);
	(*tools)->pos = NULL;
}
