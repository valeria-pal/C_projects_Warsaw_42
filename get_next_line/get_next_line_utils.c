/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:18:09 by vpaliash          #+#    #+#             */
/*   Updated: 2025/03/04 14:45:49 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	char	*arr;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
        return NULL;
    if (!s1)
        return ft_str_dup(s2);
    if (!s2)
        return ft_str_dup(s1);

	i = 0;
	j = 0;
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	arr = (char *)malloc((s1_size + s2_size + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	while (s1 && s1[j])
		arr[i++] = s1[j++];
	j = 0;
	while (s2[j])
		arr[i++] = s2[j++];
	arr[i] = '\0';
	free(s1);
	return (arr);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = ft_strlen(s);
	dup = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*extract_line(char **saved_text)
{
	size_t	i;
	char	*line;
	char	*new_saved;

	i = 0;
	while ((*saved_text)[i] && (*saved_text)[i] != '\n')
		i++;
	if ((*saved_text)[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while ((*saved_text)[i] && (*saved_text)[i] != '\n')
	{
		line[i] = (*saved_text)[i];
		i++;
	}
	if ((*saved_text)[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	new_saved = ft_strdup(*saved_text + i);
	free(*saved_text);
	*saved_text = new_saved;
	return (line);
}
