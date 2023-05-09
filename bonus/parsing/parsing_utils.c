/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:26:05 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/26 12:50:28 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_zero(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] != '0')
		return (0);
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

void	free_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg[i] != NULL)
	{
		free(arg[i]);
		arg[i] = NULL;
		i++;
	}
	free(arg);
	arg = NULL;
}

t_list	*check_if_numbers(int argc, char *argv[])
{
	int		i;
	int		j;
	char	**arg;
	t_list	*stack_a;
	long	num;

	i = 0;
	stack_a = NULL;
	while (++i < argc)
	{
		arg = ft_split(argv[i], ' ');
		j = -1;
		while (arg[++j])
		{
			num = ft_atoi(arg[j]);
			if (num == 0 || num > 2147483647 || num < -2147483648)
			{
				if (num != 0 || !is_zero(arg[j]))
					ft_error();
			}
			ft_lstadd_back(&stack_a, ft_lstnew(num));
		}
		free_arg(arg);
	}
	return (stack_a);
}

int	check_if_sorted(t_list *stack_a)
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
	if (!stack_a || i == size - 1)
		return (1);
	return (0);
}

void	check_if_duplicate(t_list *stack)
{
	int		i;
	int		j;
	int		size;
	t_list	*tmp;

	size = ft_lstsize(stack);
	i = 0;
	while (i < size - 1)
	{
		j = i;
		tmp = stack->next;
		while (j < size - 1)
		{
			if (stack->content == tmp->content)
				ft_error();
			tmp = tmp->next;
			j++;
		}
		stack = stack->next;
		i++;
	}
}
