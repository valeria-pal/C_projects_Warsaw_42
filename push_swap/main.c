/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:16:24 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/24 15:15:15 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap

int main(int argc, char **argv)
{
	if (is_input_correct(argc, argv))
	{
		Node *a = insert_data_to_stack(argc, argv);
		
		push_swap(&a);
		free_stack(&a);
	}
	return 0;
}

