/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:14:25 by vpaliash          #+#    #+#             */
/*   Updated: 2024/12/16 22:22:49 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_size;

	i = 0;
	if (!big)
		return (NULL);
	little_size = ft_strlen(little);
	if (little_size == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (j < little_size && big[i + j] == little[j] && i + j < len)
		{
			if (j + 1 == little_size)
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
