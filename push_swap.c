/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:53:01 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/09 15:27:47 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*push_not_exist_to_stack_b(t_list **stack_a, int *lis)
{
	t_list	*stack_b;
	t_list 	*sa_tmp;
	int		size;
	int		i;
	int		j;
	int		exist;

	sa_tmp = *stack_a;
	size = ft_lstsize(sa_tmp);
	stack_b = NULL;
	i = 0;
	while (i < size)
	{
		j = 0;
		exist = 0;
		while (j < 6)
		{
			if (sa_tmp->content == lis[j])
				exist = 1;
			j++;
		}
		/* Here we have to push all inexist nums in lis to stack B
		if (!exist)
			pb(&(*stack_a), &stack_b);
		*/
		sa_tmp = sa_tmp->next;
		i++;
	}
	return (stack_b);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*lis;

	stack_a = parsing(argc, argv);
	lis = find_lis(stack_a);
	stack_b = push_not_exist_to_stack_b(&stack_a, lis);
	printf("stack A : \n");
	while (stack_a->next != NULL)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
		if (stack_a->next == NULL)
			printf("%d\n", stack_a->content);
	}
	printf("stack B : \n");
	while (stack_b->next != NULL)
	{
		printf("%d\n", stack_b->content);
		stack_b = stack_b->next;
		if (stack_b->next == NULL)
			printf("%d\n", stack_b->content);
	}
	return (0);
}