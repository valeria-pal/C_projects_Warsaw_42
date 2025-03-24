/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:23:24 by vpaliash          #+#    #+#             */
/*   Updated: 2025/03/24 19:30:23 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_two_elements_in_stack(Node **top)
{
	Node	*first;
	Node	*second;

	if (is_stack_empty(*top) || is_stack_has_one_element(*top))
		return ;
	first = *top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*top = second;
} // two ways - reconnecting nodes pointers or swap nodes data
void	swap_a(Node **top_a)
{
	swap_two_elements_in_stack(top_a);
	ft_printf(1, "sa\n");
}
void	swap_b(Node **top_b)
{
	swap_two_elements_in_stack(top_b);
	ft_printf(1, "sb");
}

void	swap_a_b(Node **top_a, Node **top_b)
{
	swap_two_elements_in_stack(top_a);
	swap_two_elements_in_stack(top_b);
	ft_printf(1, "ss");
}
