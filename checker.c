/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:25:10 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/23 14:32:53 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*line;

	stack_b = NULL;
	stack_a = parsing(argc, argv);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
			sa(&stack_a);
		else if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
			sb(&stack_b);
		else if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
			ss(&stack_a, &stack_b);
		else if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
			pa(&stack_a, &stack_b);
		else if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
			pb(&stack_a, &stack_b);
		else if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
			ra(&stack_a);
		else if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
			rb(&stack_a);
		else if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
			rr(&stack_a, &stack_b);
		else if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
			rra(&stack_a);
		else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
			rrb(&stack_b);
		else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
			rrr(&stack_a, &stack_b);
		else
			ft_error();
		free(line);
		line = get_next_line(0);
	}
	check_if_sorted(stack_a);
	printf("KO\n");
	return (0);
}