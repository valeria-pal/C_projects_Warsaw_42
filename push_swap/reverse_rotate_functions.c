/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:47:05 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/30 16:43:37 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shift_down_all_elements_by_one(t_node **top)
{
	t_node	*last;
	t_node	*second_last;

	if (is_stack_empty(*top) || is_stack_has_one_element(*top))
		return ;
	last = *top;
	second_last = *top;
	while (second_last->next->next)
		second_last = second_last->next;
	*top = second_last->next;
	second_last->next = NULL;
	(*top)->next = last;
}

void	reverse_rotate_a(t_node **top_a)
{
	shift_down_all_elements_by_one(top_a);
	ft_printf(1, "rra");
}

void	reverse_rotate_b(t_node **top_b)
{
	shift_down_all_elements_by_one(top_b);
	ft_printf(1, "rrb");
}

void	reverse_rotate_a_b(t_node **top_a, t_node **top_b)
{
	shift_down_all_elements_by_one(top_a);
	shift_down_all_elements_by_one(top_b);
	ft_printf(1, "rrr");
}
