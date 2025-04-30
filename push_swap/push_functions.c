/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:23:20 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/30 16:42:05 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_element_to_stack(t_node **dest, t_node **src)
{
	t_node	*temp;

	if (is_stack_empty(*src))
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	push_a(t_node **top_a, t_node **top_b)
{
	push_element_to_stack(top_a, top_b);
	ft_printf(1, "pa");
}

void	push_b(t_node **top_b, t_node **top_a)
{
	push_element_to_stack(top_b, top_a);
	ft_printf(1, "pb");
}
