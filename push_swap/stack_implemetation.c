/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_implemetation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:30:32 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/18 15:08:47 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static Node	*create_new_node(int data)
{
	Node	*new_node;

	new_node = (Node *)malloc(sizeof(Node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

int	is_stack_empty(Node *top)
{
	return (top == NULL);
}
int	is_stack_has_one_element(Node *top)
{
	return (top != NULL && top->next == NULL);
}

static void	add_node_to_stack_end(Node **top, int data)
{
	Node	*new_node;
	Node	*temp;

	new_node = create_new_node(data);
	if (!new_node)
		return ;
	temp = *top;
	if (is_stack_empty(*top))
	{
		*top = new_node;
		return ;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
}
void	print_stack(Node *top) // dont forget to delete
{
	while (top)
	{
		printf("%ld", top->data);
		top = top->next;
	}
	write(1, "\n", 1);
}

Node	*insert_data_to_stack(int argc, char **argv)
{
	int i;
	Node *top = NULL;

	i = 1;

	while (i < argc)
	{
		add_node_to_stack_end(&top, ft_atoi(argv[i]));
		i++;
	}
	return (top);
}