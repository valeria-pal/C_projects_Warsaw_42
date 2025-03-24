/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:23:20 by vpaliash          #+#    #+#             */
/*   Updated: 2025/03/24 21:10:51 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_element_to_stack(Node **top_a, Node ** top_b)
{
	if (is_stack_empty(*top_b)  )
	return;
	
	
}

void push_a(Node **top_a, Node ** top_b)
{
	if (is_stack_empty(*top_b)  )
	return;
	push_element_to_stack(top_a,top_a);
	ft_printf(1,"pa");
}
void push_b(Node **top_a, Node ** top_b)
{
	if (is_stack_empty(*top_a)  )
	return;
	push_element_to_stack(top_a,top_a);
	ft_printf(1,"pb");
}