/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:23:20 by vpaliash          #+#    #+#             */
/*   Updated: 2025/03/25 18:59:29 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_element_to_stack(Node **dest, Node **src)
{    
	if (is_stack_empty(*src))
	return;
	
	Node	*temp;
	
	 temp = *src;
	 temp -> next = *dest;
	 *dest = *src;
	 *src = (*src) -> next;//incorrect verdion
	 
}

void	push_a(Node **top_a, Node **top_b)
{
	push_element_to_stack(top_a, top_b);
	ft_printf(1, "pa");
}
void	push_b(Node **top_b, Node **top_a)
{
	push_element_to_stack(top_b, top_a);
	ft_printf(1, "pb");
}