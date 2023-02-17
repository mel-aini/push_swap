/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:22:04 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/15 15:41:56 by mel-aini         ###   ########.fr       */
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

void	check_if_sorted(t_list *stack_a)
{
	int	size;
	int	i;

	size = ft_lstsize(stack_a);
	i = 0;
	while (i < size - 1 && stack_a->content < stack_a->next->content)
	{
		stack_a = stack_a->next;
		i++;
	}
	if (i == size - 1)
		exit(EXIT_SUCCESS);
}

void	check_if_duplicate(t_list *stack)
{
	int		i;
	int		j;
	int		size;
	t_list *tmp;

	size = ft_lstsize(stack);
	i = 0;
	while (i < size - 1)
	{
		j = i;
		tmp = stack->next;
		while (j < size - 1)
		{
			if (stack->content == tmp->content)
				invalid_arg();
			tmp = tmp->next;
			j++;
		}
		stack = stack->next;
		i++;
	}
}

t_list	*parsing(int argc, char *argv[])
{
	t_list *stack_a;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	stack_a = check_if_numbers(argc, argv);
	check_if_duplicate(stack_a);
	check_if_sorted(stack_a);
	if (argc == 3)
	{
		sa(&stack_a);
		exit(EXIT_SUCCESS);
	}
	return (stack_a);
}