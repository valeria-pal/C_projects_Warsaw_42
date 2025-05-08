/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_implemetation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:30:32 by vpaliash          #+#    #+#             */
/*   Updated: 2025/05/08 13:45:47 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_new_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

int	is_stack_empty(t_node *top)
{
	return (top == NULL);
}

int	is_stack_has_one_element(t_node *top)
{
	return (top != NULL && top->next == NULL);
}

static void	add_node_to_stack_end(t_node **top, int data)
{
	t_node	*new_node;
	t_node	*temp;

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

t_node	*insert_data_to_stack(int argc, char **argv)
{
	int		i;
	t_node	*top;

	top = NULL;
	i = 0;
	while (i < argc)
	{
		add_node_to_stack_end(&top, ft_atoi(argv[i]));
		i++;
	}
	return (top);
}
