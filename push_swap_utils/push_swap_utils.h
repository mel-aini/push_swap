/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:22:15 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/23 18:33:25 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# include "../push_swap.h"

typedef struct s_list	t_list;

typedef struct s_tools	t_tools;

void	sort_3_nums(t_list *stack_a);
void	sort_5_nums(t_list *stack_a, t_list *stack_b, int size);
void	bring_small_to_top(t_list **stack_a, t_list **stack_b, int size, int j);
int		smallest(t_list *stack_a, int elem, int size);
int		biggest(t_list *stack_a, int elem, int size);
int		min(int a, int b);

int		absolute(int n);
int		min(int a, int b);
int		max_moves(int a, int b);
int		diff(int a, int b);

t_list	*push_not_exist_to_stack_b(t_list **stack_a, t_tools *tools, int size);
int		find_best_move(t_list *stack, t_tools *tools, int size);

t_list	*iterate_b(t_list *stack_a, t_list **stack_b, t_tools *tools);
void	repeat_rr(t_list **stack_a, t_list **stack_b, int a, int b);
void	repeat_rrr(t_list **stack_a, t_list **stack_b, int a, int b);
int		*best_to_push_to_a(t_list *stack_a, t_list *stack_b, t_tools **tools);
void	elem_pos_at_a(t_list *stack_a, int elem, int **pos, int index);

int		**alloc_pos(int size);
void	free_pos(t_tools **tools);

t_list	*put_small_at_top(t_list *stack, int size, int print);

void	print_stacks(t_list *stack_a, t_list *stack_b);

#endif