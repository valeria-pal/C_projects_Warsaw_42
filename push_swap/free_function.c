/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:39:38 by vpaliash          #+#    #+#             */
/*   Updated: 2025/03/21 16:40:49 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(Node **top)
{
	Node	*temp;

	while (*top)
	{
		temp = *top;
		*top = (*top)->next;
		free(temp);
	}
	  *top = NULL;
}