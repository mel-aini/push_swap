/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:22:50 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/26 12:28:21 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../push_swap.h"

typedef struct s_list	t_list;

t_list	*parsing(int argc, char *argv[]);
t_list	*check_if_numbers(int argc, char *argv[]);
int		is_zero(char *str);
void	check_if_duplicate(t_list *stack);
int		check_if_sorted(t_list *stack_a);
void	free_arg(char **arg);
void	ft_error(void);
void	exit_process(void);

#endif