/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:23:28 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/30 16:43:56 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shift_up_all_elements_by_one(t_node **top)
{
	t_node	*first;
	t_node	*last;

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

void	rotate_a(t_node **top_a)
{
	shift_up_all_elements_by_one(top_a);
	ft_printf(1, "ra");
}

void	rotate_b(t_node **top_b)
{
	shift_up_all_elements_by_one(top_b);
	ft_printf(1, "rb");
}

void	rotate_a_b(t_node **top_a, t_node **top_b)
{
	shift_up_all_elements_by_one(top_a);
	shift_up_all_elements_by_one(top_b);
	ft_printf(1, "rr");
}
