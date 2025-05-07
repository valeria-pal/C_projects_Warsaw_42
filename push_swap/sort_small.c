/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:30:32 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/30 16:48:39 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_node *top_a)
{
	int	min;

	min = top_a->data;
	while (top_a)
	{
		if (top_a->data < min)
			min = top_a->data;
		top_a = top_a->next;
	}
	return (min);
}

void	sort_two(t_node **top_a)
{
	if ((*top_a)->data > (*top_a)->next->data)
		swap_a(top_a);
}

void	sort_three(t_node **top_a)
{
	int	first;
	int	second;
	int	third;

	first = (*top_a)->data;
	second = (*top_a)->next->data;
	third = (*top_a)->next->next->data;
	if (first > second && second < third && first < third)
		swap_a(top_a);
	else if (first > second && second > third)
	{
		swap_a(top_a);
		reverse_rotate_a(top_a);
	}
	else if (first > second && second < third && first > third)
		rotate_a(top_a);
	else if (first < second && second > third && first < third)
	{
		swap_a(top_a);
		rotate_a(top_a);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(top_a);
}

void	sort_five(t_node **top_a, t_node **top_b)
{
	int	min;

	while (stack_size(*top_a) > 3)
	{
		min = find_min(*top_a);
		if ((*top_a)->data == min)
			push_b(top_b, top_a);
		else
			rotate_a(top_a);
	}
	sort_three(top_a);
	while (*top_b)
		push_a(top_a, top_b);
}
