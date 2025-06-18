/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:31:16 by vpaliash          #+#    #+#             */
/*   Updated: 2024/12/16 20:43:25 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	size_t	i;
	char	*arr;

	i = 0;
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	arr = (char *)malloc((s1_size + s2_size + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	while (*s1)
	{
		arr[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		arr[i++] = *s2;
		s2++;
	}
	arr[i] = '\0';
	return (arr);
}
