/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:16:24 by vpaliash          #+#    #+#             */
/*   Updated: 2025/03/27 15:41:41 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap

int	main(int argc, char **argv)
{
	Node *stack_a;
	Node *stack_b;

	if (!is_input_correct(argc, argv))
		return (0);
	stack_a = insert_data_to_stack(argc, argv);
	stack_b = NULL;


	printf("\nStack a \n");
	print_stack(stack_a);
	printf("\nStack b \n");
	print_stack(stack_b);
	
	swap_a(&stack_a);
	printf("\nStack a \n");
	print_stack(stack_a);
	printf("\nStack b \n");
	print_stack(stack_b);


	push_b(&stack_b, &stack_a);
	push_b(&stack_b, &stack_a);
	push_b(&stack_b, &stack_a);
	printf("\nStack a \n");
	print_stack(stack_a);
	printf("\nStack b \n");
	print_stack(stack_b);

	rotate_a_b(&stack_a, &stack_b);
	printf("\nStack a \n");
	print_stack(stack_a);
	printf("\nStack b \n");
	print_stack(stack_b);

	
	reverse_rotate_a_b(&stack_a, &stack_b);
	printf("\nStack a \n");
	print_stack(stack_a);
	printf("\nStack b \n");
	print_stack(stack_b);

	swap_a(&stack_a);
	printf("\nStack a \n");
	print_stack(stack_a);
	printf("\nStack b \n");
	print_stack(stack_b);

	push_a(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
	printf("\nStack a \n");
	print_stack(stack_a);
	printf("\nStack b \n");
	print_stack(stack_b);

	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}