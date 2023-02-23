/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:11:12 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/23 18:28:56 by mel-aini         ###   ########.fr       */
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
	printf("stack B : \n");
	while (i < size_b)
	{
		printf("%d | ", stack_b->content);
		stack_b = stack_b->next;
		i++;
	}
	printf("\n");
}

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(int content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

void    ra(t_list **stack_a, int print)
{
	t_list *tmp;
	t_list	*ptr;
	
	ptr = *stack_a;
	tmp = ft_lstnew((*stack_a)->content);
	*stack_a = (*stack_a)->next;
	free(ptr);
	ptr = *stack_a;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = tmp;
	if (print)
		printf("ra\n");
}


void	test(t_list *stack)
{
	ra(&stack, 0);
}

int	main(void)
{
	static t_list	*stack_a;

	for (int i = 1; i < 5; i++)
		ft_lstadd_back(&stack_a, ft_lstnew(i));
	test(stack_a);
}