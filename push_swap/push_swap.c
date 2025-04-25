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
#include <stdlib.h>

static int	stack_size(Node *top)
{
	int	count = 0;
	while (top)
	{
		count++;
		top = top->next;
	}
	return (count);
}


int * stack_to_arr(Node *top )
{
	int size = stack_size(top);
	int i = 0;
	int *int_arr = malloc(size*sizeof(int));
	if (!int_arr)
	return -1;
	Node *temp = top;
	if (!int_arr)
	return NULL;

	while(temp)
	{
		int_arr[i++] = temp->data;
		temp = temp->next;
	}
	return int_arr;
	
}
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

 
int find_median_from_stack(Node *top)
{
	int *int_arr = stack_to_arr(top);
	if (!int_arr)
		return -1;
	int size = stack_size(top);
	int i = 0;
	bubble_sort(int_arr, size);
	int median = int_arr[size/2];
	
	return median;
	
}

void bubble_sort (int * tab, int size)

{
	int temp;
	int i = 0;
	int swapped = 1;
	while(swapped)
	{
		swapped = 0;
		i=0;
	while(i <size)
	{
		if(tab[i] > tab[i+1])
		{
		swap (tab[i], tab[i+1]);
		swapped = 1;
		}
	
	i++;
	}
}
}


void split_by_median(Node **a, Node **b, int median)
{
	int i = 0;
int size = stack_size(*a);
while (i < size)
{
	if ((*a)->data < median)
		push_b(a, b);
	else
		rotate_a(a);
	i++;
}
}

