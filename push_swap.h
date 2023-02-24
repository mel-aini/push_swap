/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:53:40 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/24 10:35:06 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "parsing/parsing.h"
# include "push_swap_utils/push_swap_utils.h"
# include "operations/operations.h"
# include "libft/libft.h"
# include "find_lis/find_lis.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define ERROR "Error\n"

typedef struct s_list	t_list;

typedef struct s_tools
{
	int		**len;
	int		**indexes;
	int		*lis;
	int		lis_size;
	int		*lis_indexes;
	int		**pos;
	int		sb_size;
	int		*pos_b;
	t_list	**tmp_stack;
	t_list	*best_lis;
	int		index;
	int		stack_size;
}				t_tools;

void	print_stacks(t_list *stack_a, t_list *stack_b);

#endif