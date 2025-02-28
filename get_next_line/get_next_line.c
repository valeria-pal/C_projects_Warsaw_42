/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:18:14 by vpaliash          #+#    #+#             */
/*   Updated: 2025/02/21 18:44:36 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *saved_text;
	char buffer[BUFFER_SIZE + 1];
	ssize_t bytes_read;

	saved_text = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	while (!saved_text || !ft_strchr(saved_text, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		saved_text = ft_strjoin(saved_text, buffer);
	}

	if (saved_text && *saved_text)
		return (extract_line(&saved_text));

	free(saved_text);
	saved_text = NULL;
	return (NULL);
}