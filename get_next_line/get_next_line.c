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
	static char	*storage;
	char		*line;
	ssize_t		bytes_read;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(storage, '\n') && (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	if (!storage || *storage == '\0')
		return (NULL);
	line = extract_line(storage);
	storage = clean_storage(storage);
	return (line);
}
