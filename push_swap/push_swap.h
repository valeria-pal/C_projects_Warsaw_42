/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:58:50 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/24 15:05:07 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>


typedef struct Node
{
	 int	data;
	struct Node	*next;
}				Node;


int		is_input_correct(int argc, char **argv);
Node	*insert_data_to_stack(int argc, char **argv);


void	free_stack(Node **top);


int		is_stack_empty(Node *top);
int		is_stack_has_one_element(Node *top);


void	swap_a(Node **top_a);
void	swap_b(Node **top_b);
void	swap_a_b(Node **top_a, Node **top_b);


void	push_a(Node **top_a, Node **top_b);
void	push_b(Node **top_b, Node **top_a);


void	rotate_a(Node **top_a);
void	rotate_b(Node **top_b);
void	rotate_a_b(Node **top_a, Node **top_b);


void	reverse_rotate_a(Node **top_a);
void	reverse_rotate_b(Node **top_b);
void	reverse_rotate_a_b(Node **top_a, Node **top_b);


void sort_two(Node ** top_a);
void sort_three(Node ** top_a);
void sort_three_b(Node **top_b);
void sort_five(Node **top_a, Node **top_b);


void	ft_printf(int fd, char *str);
void	print_stack(Node *top);

int	stack_size(Node *top);


void push_swap(Node **a);
void radix_sort(Node **a, Node **b);

void index_stack(Node *top);

int get_max_bits(Node *top);


#endif
