/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:22:04 by mel-aini          #+#    #+#             */
/*   Updated: 2023/05/11 17:47:32 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_list	*parsing(int argc, char *argv[])
{
	t_list	*stack_a;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	stack_a = check_if_numbers(argc, argv);
	check_if_duplicate(stack_a);
	return (stack_a);
}
