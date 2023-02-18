/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:53:01 by mel-aini          #+#    #+#             */
/*   Updated: 2023/02/18 18:43:59 by mel-aini         ###   ########.fr       */
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

int	absolute(int n)
{
	if (n > 0)
		return (n);
	else if (n < 0)
		return (n * -1);
	return (0);
}

int	find_best_move(t_list *stack, t_tools **tools)
{
	int	i;
	int	best;
	int	size;
	int	exist;
	int	k;
	int	j;
	int	n;

	size = ft_lstsize(stack);
	(*tools)->pos_b = malloc(sizeof(int) * size - (*tools)->lis_size);
	if (!(*tools)->pos_b)
		exit(EXIT_FAILURE);
	i = 0;
	k = 0;
	while (i <= size / 2)
	{
		j = 0;
		exist = 0;
		while (j < (*tools)->lis_size)
		{
			if (stack->content == (*tools)->lis[j])
			{
				exist = 1;
				break ;
			}
			j++;
		}
		if (!exist)
		{
			(*tools)->pos_b[k] = i;
			k++;
		}
		stack = stack->next;
		i++;
	}
	j = ((size / 2) * -1) + (1 - size % 2);
	while (i < size)
	{
		n = 0;
		exist = 0;
		while (n < (*tools)->lis_size)
		{
			if (stack->content == (*tools)->lis[n])
			{
				exist = 1;
				break ;
			}
			n++;
		}
		if (!exist)
		{
			(*tools)->pos_b[k] = j;
			k++;
		}
		stack = stack->next;
		i++;
		j++;
	}
	i = 0;
	best = i;
	while (++i < size - (*tools)->lis_size)
	{
		if (absolute((*tools)->pos_b[i]) < absolute((*tools)->pos_b[best]))
			best = i;
	}
	return ((*tools)->pos_b[best]);
}

t_list	*push_not_exist_to_stack_b(t_list **stack_a, t_tools *tools)
{
	t_list	*stack_b;
	t_list 	*sa_tmp;
	int		size;
	int		i;
	int		j;
	int		k;
	int		n;
	int		exist;
	int		*pos;
	int		best;

	sa_tmp = *stack_a;
	size = ft_lstsize(sa_tmp);
	stack_b = NULL;
	if (size == tools->lis_size)
		return (stack_b);
	i = 0;
	while (i < size - tools->lis_size)
	{
		best = find_best_move(sa_tmp, &tools);
		j = 0;
		if (best > 0)
		{
			while (j < best)
			{
				ra(&sa_tmp, 1);
				j++;
			}
		}
		else if (best < 0)
		{
			while (j < absolute(best))
			{
				rra(&sa_tmp, 1);
				j++;
			}
		}
		free(tools->pos_b);
		tools->pos_b = NULL;
		pb(&sa_tmp, &stack_b);
		i++;
	}
	*stack_a = sa_tmp;
	return (stack_b);
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

int	pos_of_largest(t_list *stack_a, int size)
{
	int		i;
	int		j;
	t_list	*tmp;

	tmp = stack_a->next;
	i = 0;
	while (i <= size / 2)
	{
		if (stack_a->content > tmp->content)
			return (i + 1);
		stack_a = stack_a->next;
		tmp = tmp->next;
		i++;
	}
	j = ((size / 2) * -1) + (1 - size % 2);
	while (i < size)
	{
		if (i == size - 1)
			return (0);
		if (stack_a->content > tmp->content)
			return (j + 1);
		stack_a = stack_a->next;
		tmp = tmp->next;
		i++;
		j++;
		if (i == size - 1)
			return (j);
	}
	return (0);
}

void	find_pos_of_elem_at_stack_a(t_list *stack_a, int elem, int **pos, int index)
{
	int		i;
	int		j;
	int		**curr;
	int		size;
	t_list	*stack_a_head;

	size = ft_lstsize(stack_a);
	stack_a_head = stack_a;
	i = 0;
	j = ((size / 2) * -1) + (1 - size % 2);
	while (i <= size / 2)
	{
		if (i == size - 1 && elem < stack_a_head->content)
		{
			pos[index][0] = 0;
			return ;
		}
		else if (i != size - 1 && stack_a->content < elem && elem < stack_a->next->content)
		{
			if (i == size / 2)
				pos[index][0] = j;
			else
				pos[index][0] = i + 1;
			return ;	
		}
		stack_a = stack_a->next;
		i++;
	}
	while (i < size)
	{
		if (i == size - 1 && elem < stack_a_head->content)
		{
			pos[index][0] = 0;
			return ;
		}
		else if (i != size - 1 && stack_a->content < elem && elem < stack_a->next->content)
		{
			pos[index][0] = j + 1;
			return ;	
		}
		stack_a = stack_a->next;
		i++;
		j++;
	}
	pos[index][0] = pos_of_largest(stack_a_head, size);
}

int	max_moves(int a, int b)
{
	if (a < 0 && b < 0)
		return (min(absolute(a), absolute(b)) + absolute(absolute(a) - absolute(b)));
	else if (a > 0 && b > 0)
		return (min(a, b) + absolute(a - b));
	else
		return (absolute(a) + absolute(b));
}

void	free_pos(t_tools **tools)
{
	int	i;

	i = 0;
	while (i < (*tools)->sb_size)
	{
		free((*tools)->pos[i]);
		(*tools)->pos[i] = NULL;
		i++;
	}
	free((*tools)->pos);
	(*tools)->pos = NULL;
}

int	*find_best_elem_at_b_to_push_to_a(t_list *stack_a, t_list *stack_b, t_tools **tools)
{
	int	i;
	int	j;
	int	**pos;
	int	best;

	(*tools)->sb_size = ft_lstsize(stack_b);
	pos = alloc_pos(stack_b, (*tools)->sb_size);
	(*tools)->pos = pos;
	i = 0;
	while (i <= (*tools)->sb_size / 2)
	{
		pos[i][1] = i;
		find_pos_of_elem_at_stack_a(stack_a, stack_b->content, pos, i);
		stack_b = stack_b->next;
		i++;
	}
	j = (((*tools)->sb_size / 2) * -1) + (1 - (*tools)->sb_size % 2);
	while (i < (*tools)->sb_size)
	{
		pos[i][1] = j;
		find_pos_of_elem_at_stack_a(stack_a, stack_b->content, pos, i);
		stack_b = stack_b->next;
		i++;
		j++;
	}
	i = 0;
	best = 0;
	while (++i < (*tools)->sb_size)
	{
		if (max_moves(pos[i][0], pos[i][1]) < max_moves(pos[best][0], pos[best][1]))
			best = i;
	}
	return (pos[best]);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
	return (0);
}

int	diff(int a, int b)
{
	return (a - b);
}

void	repeat_rr(t_list **stack_a, t_list **stack_b, int a, int b)
{
	int	j;
	t_list	*sb_tmp;
	t_list	*sa_tmp;

	sa_tmp = *stack_a;
	sb_tmp = *stack_b;
	j = 0;
	while (j < min(a, b))
	{
		rr(&sa_tmp, &sb_tmp);
		j++;
	}
	j = diff(a, b);
	while (j != 0)
	{
		if (j > 0)
		{
			ra(&sa_tmp, 1);
			j--;
		}
		else
		{
			rb(&sb_tmp);
			j++;
		}
	}
	*stack_a = sa_tmp;
	*stack_b = sb_tmp;
}

void	repeat_rrr(t_list **stack_a, t_list **stack_b, int a, int b)
{
	int	j;
	t_list	*sb_tmp;
	t_list	*sa_tmp;

	sa_tmp = *stack_a;
	sb_tmp = *stack_b;
	j = 0;
	while (j < min(absolute(a), absolute(b)))
	{
		rrr(&sa_tmp, &sb_tmp);
		j++;
	}
	j = diff(absolute(a), absolute(b));
	while (j != 0)
	{
		if (j > 0)
		{
			rra(&sa_tmp, 1);
			j--;
		}
		else
		{
			rrb(&sb_tmp);
			j++;
		}
	}
	*stack_a = sa_tmp;
	*stack_b = sb_tmp;
}

t_list	*iterate_b(t_list *stack_a, t_list **stack_b, t_tools *tools)
{
	int		*best_elem;
	int		i;
	int		j;
	int		size_b;
	t_list	*stack_b_tmp;

	stack_b_tmp = *stack_b;
	size_b = ft_lstsize(stack_b_tmp);
	i = 0;
	while (i < size_b)
	{
		best_elem = find_best_elem_at_b_to_push_to_a(stack_a, stack_b_tmp, &tools);
		if (best_elem[0] > 0 && best_elem[1] > 0)
			repeat_rr(&stack_a, &stack_b_tmp, best_elem[0], best_elem[1]);
		else if (best_elem[0] < 0 && best_elem[1] < 0)
			repeat_rrr(&stack_a, &stack_b_tmp, best_elem[0], best_elem[1]);
		else
		{
			j = 0;
			while (j < absolute(best_elem[1]))
			{
				if (best_elem[1] > 0)
					rb(&stack_b_tmp);
				else if (best_elem[1] < 0)
					rrb(&stack_b_tmp);
				j++;
			}
			j = 0;
			while (j < absolute(best_elem[0]))
			{
				if (best_elem[0] > 0)
					ra(&stack_a, 1);
				else if (best_elem[0] < 0)
					rra(&stack_a, 1);
				j++;
			}
		}
		free_pos(&tools);
		pa(&stack_a, &stack_b_tmp);
		i++;
	}
	*stack_b = stack_b_tmp;
	return (stack_a);
}

void	algo_of_3_nums(t_list *stack_a)
{
	while (!check_if_sorted(stack_a))
	{
		if (stack_a->content > stack_a->next->content && stack_a->next->content > stack_a->next->next->content)
			ra(&stack_a, 1);
		else if (stack_a->content > stack_a->next->content)
			sa(&stack_a);
		else
			ra(&stack_a, 1);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_tools	tools;
	int		size_a;

	// atexit(leaks);
	stack_a = parsing(argc, argv);
	size_a = ft_lstsize(stack_a);
	if (size_a == 3)
		algo_of_3_nums(stack_a);
	else
	{
		find_lis(stack_a, &tools);
		stack_b = push_not_exist_to_stack_b(&stack_a, &tools);
		stack_a = iterate_b(stack_a, &stack_b, &tools);
		stack_a = put_small_at_top(stack_a, ft_lstsize(stack_a), 1);	
	}
	system("leaks push_swap");
	// print_stacks(stack_a, stack_b);
	// check_if_sorted(stack_a);
	// printf("NOT SORTED\n");
	return (0);
}