/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:01:53 by vpaliash          #+#    #+#             */
/*   Updated: 2024/12/16 21:28:07 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;
	size_t	src_size;

	i = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size <= dst_size)
	{
		return (size + src_size);
	}
	while ((dst_size < size - 1) && src[i])
	{
		dst[dst_size] = src[i];
		dst_size++;
		i++;
	}
	if (dst_size < size)
		dst[dst_size] = '\0';
	return (dst_size + (src_size - i));
}
