/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:22:12 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/25 18:28:48 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



static int  is_sorted(Node *top)
{
	while (top && top->next)
	{
		if (top->data > top->next->data)
			return 0;
		top = top->next;
	}
	return 1;
}
void radix_sort(Node **a, Node **b)
{
	int size = stack_size(*a);
	int max_bits = get_max_bits(*a);

	for (int i = 0; i < max_bits; i++)
	{
		int j = 0;
		while (j < size)
		{
			if (((*a)->data >> i) & 1)
				rotate_a(a);
			else
				push_b(b, a);
			j++;
		}
		while (*b)
			push_a(a, b);
	}
}


void push_swap(Node **a)
{
	Node *b = NULL;
	int size = stack_size(*a);

	if (is_sorted(*a) || size <= 1)
		return;

	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, &b);
	else
	{
		index_stack(*a);
		print_stack(*a);
		radix_sort(a, &b);
	}
}
