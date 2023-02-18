/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:22:50 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/18 15:35:00 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../checker.h"

typedef struct s_list t_list;

t_list	*parsing(int argc, char *argv[]);
void	check_if_sorted(t_list *stack_a);
void	ft_error(void);
void	exit_process(void);

#endif