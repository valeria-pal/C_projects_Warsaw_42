/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:16:24 by vpaliash          #+#    #+#             */
/*   Updated: 2025/03/20 17:01:54 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 

int main (int argc, char ** argv)
{
	Node * stack_a;
	
	if (!is_input_correct(argc, argv))
	return 0;
	stack_a = insert_data_to_stack(argc,argv);
	print_stack(stack_a);
	return 0;
}