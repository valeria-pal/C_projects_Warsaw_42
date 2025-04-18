/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:58:50 by vpaliash          #+#    #+#             */
/*   Updated: 2025/04/18 15:04:20 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h> //dont forget to delete
# include <stdlib.h>
# include <unistd.h>

typedef struct Node
{
	long int	data;
	struct Node	*next;
}				Node;

void			ft_printf(int fd, char *str);
int				is_input_correct(int argc, char **argv);
Node			*insert_data_to_stack(int argc, char **argv);
void			free_stack(Node **top);
void	print_stack(Node *top); // dont forget to delete
int				is_stack_empty(Node *top);
int				is_stack_has_one_element(Node *top);
void			swap_a(Node **top_a);
void			swap_b(Node **top_b);
void			swap_a_b(Node **top_a, Node **top_b);
void			push_a(Node **top_a, Node **top_b);
void			push_b(Node **top_b, Node **top_a);
void			rotate_a(Node **top_a);
void			rotate_b(Node **top_b);
void			rotate_a_b(Node **top_a, Node **top_b);
void			reverse_rotate_a(Node **top_a);
void			reverse_rotate_b(Node **top_b);
void			reverse_rotate_a_b(Node **top_a, Node **top_b);
int				is_stack_have_only_positive_numbers(Node *top);
void			make_stack_with_only_positive_numbers(Node **top);
void			restore_original_stack_values(Node **top, long min);
long			find_min_in_stack(Node *top);
void			sort_stack(Node **top_a, Node **top_b);
#endif