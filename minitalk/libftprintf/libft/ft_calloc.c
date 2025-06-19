/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:14:52 by vpaliash          #+#    #+#             */
/*   Updated: 2024/12/16 21:14:08 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	arr_length;

	if (nmemb != 0 && size != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	arr_length = nmemb * size;
	if (nmemb == 0 || size == 0)
		arr_length = 1;
	arr = malloc(arr_length);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, arr_length);
	return (arr);
}
