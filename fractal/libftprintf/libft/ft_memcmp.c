/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:14:11 by vpaliash          #+#    #+#             */
/*   Updated: 2024/12/16 19:18:58 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*arr1;
	const unsigned char	*arr2;
	size_t				i;

	arr1 = (const unsigned char *)s1;
	arr2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < n && (arr1[i] == arr2[i]))
	{
		i++;
	}
	if (i == n)
		return (0);
	return (arr1[i] - arr2[i]);
}
