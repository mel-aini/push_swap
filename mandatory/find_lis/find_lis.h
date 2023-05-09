/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:07:12 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/26 12:09:00 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_LIS_H
# define FIND_LIS_H

# include "../push_swap.h"

typedef struct s_tools	t_tools;

void	find_lis(t_list *stack, t_tools *tools, int size);
void	alloc_lis(t_list *stack, t_tools *tools, int size);
int		longest_index(int *len, int size);
void	alloc_elems(t_list *stack, t_tools *tools, t_list *tmp2);
void	free_all_lis_tools(t_tools *tools);
int		*fill_len(int size);

#endif