/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:32:47 by vpaliash          #+#    #+#             */
/*   Updated: 2024/12/16 19:59:20 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_empty_string(void)
{
	char	*arr;

	arr = (char *)malloc(1);
	if (!arr)
		return (NULL);
	arr[0] = '\0';
	return (arr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*arr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	if (len > size - start)
		len = size - start;
	if (start >= size)
		return (ft_empty_string());
	arr = (char *)malloc((len + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	while (s[start + i] && i < len)
	{
		arr[i] = s[start + i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
