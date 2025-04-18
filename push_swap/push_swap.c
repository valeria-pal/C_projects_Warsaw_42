/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:22:12 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/18 15:15:55 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	find_max_in_stack(Node *top)
{
	long	max;

	max = top->data;
	while (top)
	{
		if (top->data > max)
			max = top->data;
		top = top->next;
	}
	return (max);
}

static int	get_max_bits(Node *top)
{
	int	max;
	int	bits;

	max = find_max_in_stack(top);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static int	stack_size(Node *top)
{
	int	count;

	count = 0;
	while (top)
	{
		count++;
		top = top->next;
	}
	return (count);
}
void	sort_stack(Node **top_a, Node **top_b)
{
	int	i;
	int	j;

	i = 0;
	while (i < get_max_bits(*top_a))
	{
		j = 0;
		while (j < stack_size(*top_a))
		{
			if (((*top_a)->data >> i) & 1)
				rotate_a(top_a);
			else
				push_b(top_a, top_b);
			j++;
		}
		while (*top_b)
			push_a(top_a, top_b);
		i++;
	}
}
