/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:32:51 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/18 15:35:00 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_error(void)
{
	write(2, ERROR, 6);
	exit(EXIT_FAILURE);
}

void	exit_process(void)
{
	perror("push_swap");
	exit(EXIT_FAILURE);
}
