/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:25:10 by mel-aini          #+#    #+#             */
/*   Updated: 2023/05/03 15:41:29 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	free_stack(t_list *stack, int size)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (i < size)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
		tmp = NULL;
		i++;
	}
}

void	cases(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		sa(&(*stack_a), 0);
	else if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		sb(&(*stack_b), 0);
	else if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
		ss(&(*stack_a), &(*stack_b), 0);
	else if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		pa(&(*stack_a), &(*stack_b), 0);
	else if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		pb(&(*stack_a), &(*stack_b), 0);
	else if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		ra(&(*stack_a), 0);
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		rb(&(*stack_b), 0);
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
		rr(&(*stack_a), &(*stack_b), 0);
	else if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		rra(&(*stack_a), 0);
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		rrb(&(*stack_b), 0);
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
		rrr(&(*stack_a), &(*stack_b), 0);
	else
		ft_error();
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*line;

	stack_b = NULL;
	stack_a = parsing(argc, argv);
	line = get_next_line(0);
	while (line)
	{
		cases(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (check_if_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a, ft_lstsize(stack_a));
	return (0);
}
