/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:18:14 by vpaliash          #+#    #+#             */
/*   Updated: 2025/02/20 18:02:50 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <io.h>
#define BUFFER_SIZE 1024

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

char *get_next_line(int fd)
{
	char  buffer [BUFFER_SIZE];
	size_t bytesRead;
	static char * read_text;
	char * text_to_read;
	char * line;

	read_text = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
	return NULL;	
	
	while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytesRead] = '\0';
		read_text = ft_strdup();
	}	

	return line;
	
}

