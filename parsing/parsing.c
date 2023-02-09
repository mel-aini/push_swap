/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:22:04 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/09 17:40:27 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_list	*check_if_numbers(int argc, char *argv[])
{
	int		i;
	int		j;
	char	**arg;
	t_list	*stack_a;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' ') == 0)
		{
			if (ft_atoi(argv[i]) == 0)
			{
				if (ft_strncmp(argv[i], "0", ft_strlen(argv[i])) != 0)
					invalid_arg();
			}
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
		}
		else
		{
			arg = ft_split(argv[i], ' ');
			j = 0;
			while (arg[j])
			{
				if (ft_atoi(arg[j]) == 0)
				{
					if (ft_strncmp(arg[j], "0", ft_strlen(arg[j])) != 0)
						invalid_arg();
				}
				ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(arg[j])));
				j++;
			}
		}
		i++;
	}
	return (stack_a);
}

t_list	*parsing(int argc, char *argv[])
{
	t_list *stack_a;

	if (argc < 2)
		invalid_arg();
	stack_a = check_if_numbers(argc, argv);
	return (stack_a);
}