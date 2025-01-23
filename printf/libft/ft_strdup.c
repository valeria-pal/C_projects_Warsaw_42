/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:15:35 by vpaliash          #+#    #+#             */
/*   Updated: 2024/12/16 19:20:21 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	char	*arr;
	char	*start;

	size = ft_strlen(s);
	arr = (char *)malloc((size + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	start = arr;
	while (*s)
	{
		*arr = *s;
		arr++;
		s++;
	}
	*arr = '\0';
	return (start);
}
