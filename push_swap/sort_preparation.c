/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_preparation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:30:32 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/30 17:31:37 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	bubble_sort(int *tab, int size)
{
	int	i;
	int	swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				swap(&tab[i], &tab[i + 1]);
				swapped = 1;
			}
			i++;
		}
	}
}

int	stack_size(t_node *top)
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

static int	find_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	index_stack(t_node *top)
{
	int		size;
	int		*array;
	t_node	*temp;
	int		i;

	size = stack_size(top);
	array = malloc(sizeof(int) * size);
	temp = top;
	i = 0;
	if (!array)
		return ;
	while (temp)
	{
		array[i++] = temp->data;
		temp = temp->next;
	}
	bubble_sort(array, size);
	temp = top;
	while (temp)
	{
		temp->data = find_index(array, size, temp->data);
		temp = temp->next;
	}
	free(array);
}
