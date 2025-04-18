/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_handling_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:14:31 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/18 15:03:16 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	find_min_in_stack(Node *top)
{
	long	min;
	Node	*temp;

	temp = top;
	min = temp->data;
	while (temp)
	{
		if (min > temp->data)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

int	is_stack_have_only_positive_numbers(Node *top)
{
	while (top)
	{
		if (top->data < 0)
			return (0);
		top = top->next;
	}
	return (1);
}

void	make_stack_with_only_positive_numbers(Node **top)
{
	long	min;
	Node	*temp;

	temp = *top;
	min = find_min_in_stack(*top);
	while (temp)
	{
		temp->data -= min;
		temp = temp->next;
	}
}

void	restore_original_stack_values(Node **top, long min)
{
	Node *temp;

	temp = *top;
	while (temp)
	{
		temp->data += min;
		temp = temp->next;
	}
}