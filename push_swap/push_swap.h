/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:58:50 by vpaliash          #+#    #+#             */
/*   Updated: 2025/03/21 16:41:58 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"


typedef struct Node
{
	int			data;
	struct Node	*next;
}				Node;

void			ft_printf(int fd, char *str);
int	is_input_correct(int argc, char **argv);
Node	*insert_data_to_stack(int argc, char **argv);
void	free_stack(Node **top);
void	print_stack(Node *top); 
int is_stack_empty(Node * top);
int is_stack_has_one_element(Node * top);

#endif