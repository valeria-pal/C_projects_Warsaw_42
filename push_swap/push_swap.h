/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:58:50 by vpaliash          #+#    #+#             */
/*   Updated: 2025/05/08 13:04:13 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_node
{
	int				data;
	struct t_node	*next;
}					t_node;

int					is_input_correct(int argc, char **argv);
t_node				*insert_data_to_stack(int argc, char **argv);

void				free_stack(t_node **top);

int					is_stack_empty(t_node *top);
int					is_stack_has_one_element(t_node *top);

void				swap_a(t_node **top_a);
void				swap_b(t_node **top_b);
void				swap_a_b(t_node **top_a, t_node **top_b);

void				push_a(t_node **top_a, t_node **top_b);
void				push_b(t_node **top_b, t_node **top_a);

void				rotate_a(t_node **top_a);
void				rotate_b(t_node **top_b);
void				rotate_a_b(t_node **top_a, t_node **top_b);

void				reverse_rotate_a(t_node **top_a);
void				reverse_rotate_b(t_node **top_b);
void				reverse_rotate_a_b(t_node **top_a, t_node **top_b);

void				sort_two(t_node **top_a);
void				sort_three(t_node **top_a);
void				sort_five(t_node **top_a, t_node **top_b);

void				ft_printf(int fd, char *str);
void				print_stack(t_node *top);

int					stack_size(t_node *top);
int					is_sorted(t_node *top);

void				push_swap(t_node **a);

void				index_stack(t_node *top);

void				free_split(char **arr);
char				**parse_args(int argc, char **argv, int *count);

#endif
