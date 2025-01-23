/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:11:37 by vpaliash          #+#    #+#             */
/*   Updated: 2024/12/16 19:19:08 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*arr_src;
	unsigned char		*arr_dest;
	size_t				i;

	i = 0;
	arr_src = (const unsigned char *)src;
	arr_dest = (unsigned char *)dest;
	if (arr_src > arr_dest || arr_dest >= arr_src + n)
	{
		while (i < n)
		{
			arr_dest[i] = arr_src[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			arr_dest[n - 1] = arr_src[n - 1];
			n--;
		}
	}
	return (dest);
}
