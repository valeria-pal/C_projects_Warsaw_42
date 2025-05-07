/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:22:12 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/30 16:42:45 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *top)
{
	while (top && top->next)
	{
		if (top->data > top->next->data)
			return (0);
		top = top->next;
	}
	return (1);
}

static int	find_max(t_node *top)
{
	int	max;

	max = top->data;
	while (top)
	{
		if (top->data > max)
			max = top->data;
		top = top->next;
	}
	return (max);
}

static void	move_max_to_top_b(t_node **b, int max)
{
	int		pos;
	t_node	*temp;
	int		size;

	pos = 0;
	temp = *b;
	if ((*b)->data == max)
	return ;
	while (temp && temp->data != max)
	{
		temp = temp->next;
		pos++;
	}
	size = stack_size(*b);
	if (pos <= size / 2)
		while ((*b)->data != max)
			rotate_b(b);
	else
		while ((*b)->data != max)
			reverse_rotate_b(b);
}

static void	chunk_sort(t_node **a, t_node **b, int chunk_size)
{
	int	i;
	int	limit;
	int	max;

	i = 0;
	limit = chunk_size;
	while (*a)
	{
		if ((*a)->data <= limit)
		{
			push_b(b, a);
			if ((*b)->data < limit - chunk_size / 2)
				rotate_b(b);
			if (++i % chunk_size == 0)
				limit += chunk_size;
		}
		else
			rotate_a(a);
	}
	while (*b)
	{
		max = find_max(*b);
		move_max_to_top_b(b, max);
		push_a(a, b);
	}
}

void	push_swap(t_node **a)
{
	t_node	*b;
	int		size;
	int		chunk_size;
  
	chunk_size = 20;
	
	b = NULL;
	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, &b);
	else
	{
		index_stack(*a);
		chunk_sort(a, &b, chunk_size);
	}
}
