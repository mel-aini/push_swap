/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:32:50 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/07 19:03:37 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*previous;
	t_list	*current;

	if (!del || !lst)
		return ;
	previous = *lst;
	while (previous != NULL)
	{
		current = previous;
		previous = previous->next;
		del(current->content);
		free(current);
	}
	*lst = NULL;
}
