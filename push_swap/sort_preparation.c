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

static void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
static void bubble_sort (int * tab, int size)

{
	int i ;
	int swapped = 1;
	while(swapped)
	{
		swapped = 0;
		i=0;
	while(i <size - 1)
	{
		if(tab[i] > tab[i+1])
		{
		swap (&tab[i], &tab[i+1]);
		swapped = 1;
		}
	
	i++;
	}
}
} 

 int	stack_size(Node *top)
{
	int	count = 0;
	while (top)
	{
		count++;
		top = top->next;
	}
	return (count);
}

 int get_max_bits(Node *top)
{
	int max = 0;
	while (top)
	{
		if (top->data > max)
			max = top->data;
		top = top->next;
	}
	int bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return bits;
}
static int find_index(int *arr, int size, int value)
{
	for (int i = 0; i < size; i++)
		if (arr[i] == value)
			return i;
	return -1;
}

void index_stack(Node *top)
{
	int size = stack_size(top);
	int *array = malloc(sizeof(int) * size);
	
	Node *temp = top;
	int i = 0;

	if (!array)
		return;

	while (temp)
		array[i++] = temp->data, temp = temp->next;

	bubble_sort(array, size);
	temp = top;
	while (temp)
	{
		temp->data = find_index(array, size, temp->data);
		temp = temp->next;
	}
	free(array);
}






