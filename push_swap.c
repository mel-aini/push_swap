/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:53:01 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/24 18:28:49 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	i = 0;
	printf("stack A : \n");
	while (i < size_a)
	{
		printf("%d | ", stack_a->content);
		stack_a = stack_a->next;
		i++;
	}
	i = 0;
	printf("\n");
	if (size_b != 0)
	{
		printf("stack B : \n");
		while (i < size_b)
		{
			printf("%d | ", stack_b->content);
			stack_b = stack_b->next;
			i++;
		}
		printf("\n");
	}
}

void	leaks(void)
{
	system("leaks push_swap");
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_tools	tools;
	int		size_a;

	stack_a = parsing(argc, argv);
	size_a = ft_lstsize(stack_a);
	if (size_a <= 3)
		sort_3_nums(stack_a, size_a);
	else if (size_a <= 5)
		sort_5_nums(stack_a, NULL, size_a);
	else
	{
		find_lis(stack_a, &tools, size_a);
		stack_b = push_not_exist_to_stack_b(&stack_a, &tools, size_a);
		stack_a = iterate_b(stack_a, &stack_b, &tools);
		stack_a = put_small_at_top(stack_a, ft_lstsize(stack_a), 1);
		// print_stacks(stack_a, NULL);
	}
	return (0);
}
