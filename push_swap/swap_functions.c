/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:23:24 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/30 16:51:44 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_two_elements_in_stack(t_node **top)
{
	t_node	*first;
	t_node	*second;

	if (is_stack_empty(*top) || is_stack_has_one_element(*top))
		return ;
	first = *top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*top = second;
}

void	swap_a(t_node **top_a)
{
	swap_two_elements_in_stack(top_a);
	ft_printf(1, "sa");
}

void	swap_b(t_node **top_b)
{
	swap_two_elements_in_stack(top_b);
	ft_printf(1, "sb");
}

void	swap_a_b(t_node **top_a, t_node **top_b)
{
	swap_two_elements_in_stack(top_a);
	swap_two_elements_in_stack(top_b);
	ft_printf(1, "ss");
}
