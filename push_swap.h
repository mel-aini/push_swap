/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:53:40 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/18 12:28:38 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "parsing/parsing.h"
# include "operations/operations.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define ERROR "Error\n"

typedef struct s_list t_list;

typedef struct	s_tools
{
	int	*lis;
	int	lis_size;
	int	**pos;
	int	sb_size;
	int	*pos_b;
}				t_tools;

void	find_lis(t_list *stack, t_tools *tools);
t_list	*put_small_at_top(t_list *stack, int size, int print);
int		min(int a, int b);

#endif