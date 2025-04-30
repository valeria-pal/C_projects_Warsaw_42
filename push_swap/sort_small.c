/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:30:32 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/24 15:15:15 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_min(Node *top_a)
{
	int min = top_a->data;
	while (top_a)
	{
		if (top_a->data < min)
			min = top_a->data;
		top_a = top_a->next;
	}
	return min;
}

void sort_two(Node ** top_a)
{
    if ((*top_a)->data > (*top_a)->next->data)
    swap_a(top_a);
}


void sort_three(Node ** top_a)
{
int first = (*top_a)->data;
int second = (*top_a)->next->data;
int third = (*top_a)->next->next->data;

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
void sort_three_b(Node **top_b)
{
	int first = (*top_b)->data;
	int second = (*top_b)->next->data;
	int third = (*top_b)->next->next->data;

	if (first < second && second > third && first > third)
		swap_b(top_b);
	else if (first < second && second < third)
	{
		swap_b(top_b);
		rotate_b(top_b);
	}
	else if (first > second && second < third && first > third)
		rotate_b(top_b);
	else if (first > second && second > third)
		return; 
	else if (first < second && second > third && first < third)
		reverse_rotate_b(top_b);
	else if (first > second && second < third && first < third)
	{
		swap_b(top_b);
		reverse_rotate_b(top_b);
	}
}

void sort_five(Node **top_a, Node **top_b)
{
	int min;

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
