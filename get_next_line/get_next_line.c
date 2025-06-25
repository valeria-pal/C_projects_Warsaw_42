/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:18:14 by vpaliash          #+#    #+#             */
/*   Updated: 2025/03/04 14:47:47 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved_text;	
	char		*buffer;
	ssize_t		bytes_read;
	char * temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(saved_text, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_str_join(saved_text, buffer);
		free(saved_text);
		saved_text = temp;
	}
	free(buffer);
	if (saved_text && *saved_text)
		return (extract_line(&saved_text));
	free(saved_text);
	saved_text = NULL;
	return (NULL);
}
