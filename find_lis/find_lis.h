/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:07:12 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/23 15:09:39 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_LIS_H
# define FIND_LIS_H

# include "../push_swap.h"

typedef struct s_tools t_tools;

void	find_lis(t_list *stack, t_tools *tools, int	size);
void	init_tools(t_tools *tools, t_list *stack, int size);
t_list	*dup_stack(t_list *stack, int size);
t_list	*dup_stack_2(t_list *stack, int size);
t_list	*put_small_of_tmp_at_top(t_list *stack, int size);
t_list	*put_max_of_tmp_at_bottom(t_list *stack, int size);

void	find_longest_lis(t_tools *tools, int size);
void	alloc_lis(t_tools *tools, int size, int index);
int		longest_index(int *len, int size);
void	free_all_lis_tools(t_tools *tools);
int		*fill_len(int size);

#endif