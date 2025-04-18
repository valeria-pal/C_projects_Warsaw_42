/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:16:24 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/18 15:24:46 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap

int	main(int argc, char **argv)
{
	Node *stack_a;
	Node *stack_b;
	long min = 0;

	if (!is_input_correct(argc, argv))
		return (0);

	stack_a = insert_data_to_stack(argc, argv);
	stack_b = NULL;

	if (!is_stack_have_only_positive_numbers(stack_a))
	{
		min = find_min_in_stack(stack_a);
		make_stack_with_only_positive_numbers(&stack_a);
	}

	sort_stack(&stack_a, &stack_b);

	if (min != 0)
		restore_original_stack_values(&stack_a, min);

	print_stack(stack_a);
	return (0);
}