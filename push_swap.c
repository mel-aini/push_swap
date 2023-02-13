/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:53:01 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/11 14:32:28 by mel-aini         ###   ########.fr       */
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
			{
				ra(&sa_tmp);
				*stack_a = sa_tmp;
				exist = 1;
				break ;
			}
			j++;
		}
		if (!exist)
			pb(&sa_tmp, &stack_b);
		i++;
	}
	*stack_a = sa_tmp;
	return (stack_b);
}

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
	printf("stack B : \n");
	while (i < size_b)
	{
		printf("%d | ", stack_b->content);
		stack_b = stack_b->next;
		i++;
	}
	printf("\n");
}

int	**alloc_pos(t_list *stack_a, int size)
{
	int	i;
	int	**pos;

	pos = malloc(sizeof(int *) * size);
	i = 0;
	while (i < size)
	{
		pos[i] = malloc(sizeof(int) * 2);
		i++;
	}
	return (pos);
}

void	find_best_elem_at_a_to_push_to_b(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	j;
	int	size;
	int	**pos;

	size = ft_lstsize(stack_b);
	pos = alloc_pos(stack_b, size);
	i = 0;
	while (i <= size / 2)
	{
		pos[i][1] = i;
		printf("pos of %d is : %d\n", stack_b->content, pos[i][1]);
		// find_pos_of_elem_at_stack_a(stack_a, stack_b->content, pos);
		stack_b = stack_b->next;
		i++;
	}
	j = ((size / 2) * -1) + (1 - size % 2);
	while (i < size)
	{
		pos[i][1] = j;
		printf("pos of %d is : %d\n", stack_b->content, pos[i][1]);
		// find_pos_of_elem_at_stack_a(stack_a, stack_b->content, pos);
		stack_b = stack_b->next;
		i++;
		j++;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*lis;

	stack_a = parsing(argc, argv);
	lis = find_lis(stack_a);
	stack_b = push_not_exist_to_stack_b(&stack_a, lis);
	print_stacks(stack_a, stack_b);
	find_best_elem_at_a_to_push_to_b(stack_a, stack_b);
	// system("leaks push_swap");
	return (0);
}