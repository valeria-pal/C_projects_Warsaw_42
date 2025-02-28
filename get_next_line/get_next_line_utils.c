/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:18:09 by vpaliash          #+#    #+#             */
/*   Updated: 2025/02/21 18:46:26 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	char	*arr;
	size_t	i = 0;

	if (!s1)
		s1 = "";
	if (!s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	arr = (char *)malloc((s1_size + s2_size + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	while (*s1)
		arr[i++] = *s1++;
	while (*s2)
		arr[i++] = *s2++;
	arr[i] = '\0';
	return (arr);
}

char	*ft_strdup(const char *s)
{
	size_t	len = ft_strlen(s);
	char	*dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	for (size_t i = 0; i <= len; i++)
		dup[i] = s[i];
	return (dup);
}

char	*extract_line(char **saved_text)
{
	size_t i = 0;
	char *line;
	char *new_saved_text;

	while ((*saved_text)[i] && (*saved_text)[i] != '\n')
		i++;
	if ((*saved_text)[i] == '\n')
		i++;

	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	for (size_t j = 0; j < i; j++)
		line[j] = (*saved_text)[j];
	line[i] = '\0';

	new_saved_text = ft_strdup(*saved_text + i);
	free(*saved_text);
	*saved_text = new_saved_text;
	return (line);
}


