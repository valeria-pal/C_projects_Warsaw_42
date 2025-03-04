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
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*arr_src;
	unsigned char		*arr_dest;
	size_t				i;

	i = 0;
	arr_src = (const unsigned char *)src;
	arr_dest = (unsigned char *)dest;
	while (i < n)
	{
		arr_dest[i] = arr_src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	len1 = ft_strlen(s1);
	size_t	len2 = ft_strlen(s2);

	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, len1);
	ft_memcpy(new_str + len1, s2, len2 + 1);
	free(s1);
	return (new_str);
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
char	*clean_storage(char *storage)
{
	int		i;
	int		j;
	char	*new_storage;

	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\0') // Если нет `\n`, очищаем storage
	{
		free(storage);
		return (NULL);
	}
	new_storage = malloc(ft_strlen(storage) - i);
	if (new_storage == NULL)
		return (NULL);
	j = 0;
	i++;
	while (storage[i] != '\0')
	{
		new_storage[j] = storage[i];
		i++;
		j++;
	}
	new_storage[j] = '\0';
	free(storage);
	return (new_storage);
}


char	*extract_line(char *storage)
{
    int		i;
    char		*line;

    if (storage == NULL)
        return (NULL);
    i = 0;
    while (storage[i] != '\0' && storage[i] != '\n')
        i++;
    line = malloc(i + 2);
    if (line == NULL)
        return (NULL);
    ft_memcpy(line, storage, i);
    if (storage[i] == '\n')
    {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return (line);
}
