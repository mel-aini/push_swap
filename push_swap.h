/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:53:40 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/15 14:04:14 by mel-aini         ###   ########.fr       */
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

# define INVALID_ARG "push_swap: Invalid arguments\n"

typedef struct s_list t_list;

typedef struct	s_tools
{
	int	lis_size;
}				t_tools;

int		*find_lis(t_list *stack, t_tools *tools);
t_list	*put_small_at_top(t_list *stack, int size, int print);

#endif