/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:23:28 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/24 14:42:14 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shift_up_all_elements_by_one(Node **top)
{
	Node	*first;
	Node	*last;

	if (is_stack_empty(*top) || is_stack_has_one_element(*top))
		return ;
	last = *top;
	first = (*top)->next;
	while (last->next)
		last = last->next;
	last->next = *top;
	(*top)->next = NULL;
	*top = first;
}

void	rotate_a(Node **top_a)
{
	shift_up_all_elements_by_one(top_a);
	ft_printf(1, "ra");
}

void	rotate_b(Node **top_b)
{
	shift_up_all_elements_by_one(top_b);
	ft_printf(1, "rb");
}

void	rotate_a_b(Node **top_a, Node **top_b)
{
	shift_up_all_elements_by_one(top_a);
	shift_up_all_elements_by_one(top_b);
	ft_printf(1, "rr");
}