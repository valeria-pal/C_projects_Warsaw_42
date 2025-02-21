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

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

char	*ft_strchr(const char *s, int c)
{
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
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
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

char	*extract_line(char **saved_text)
{
	char *line;
	char *new_saved_text;
	size_t i;

	i = 0;
	while ((*saved_text)[i] && (*saved_text)[i] != '\n')
		i++;

	if ((*saved_text)[i] == '\n')
		i++;

	line = ft_strdup(*saved_text);
	line[i] = '\0';
	new_saved_text = ft_strdup(*saved_text + i);

	free(*saved_text);
	*saved_text = new_saved_text;
	return (line);
}