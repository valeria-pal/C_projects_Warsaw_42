/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:13:39 by vpaliash          #+#    #+#             */
/*   Updated: 2024/12/16 19:18:50 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*arr;
	size_t				i;

	i = 0;
	arr = (const unsigned char *)s;
	while (i < n)
	{
		if (arr[i] == (unsigned char)c)
			return ((void *)(arr + i));
		i++;
	}
	return (0);
}
