/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:23:20 by vpaliash          #+#    #+#             */
/*   Updated: 2025/03/21 16:38:16 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_stack_has_one_element(Node * top)
{
	int i ;
	i = 0;

	while(top)
	{
		top = top -> next;
		i++;
	}
	if (i == 1)
	return 1;
	return 0;
}
//push_a

void swap_two_elements_in_stack(char ** top)
{
	if (is_stack_empty(*top) || is_stack_has_one_element(*top))
	return;
	
	
	
	 
	 
	
}
//push_b
// push_a + push_b