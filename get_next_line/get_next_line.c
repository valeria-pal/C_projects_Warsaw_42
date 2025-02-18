/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:18:14 by vpaliash          #+#    #+#             */
/*   Updated: 2025/02/18 16:37:48 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <io.h>
#define BUFFER_SIZE 1024

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

char *get_next_line(int fd)
{
	char buffer [BUFFER_SIZE];
    char * line;
	
	int  bytesRead = read(fd, buffer, sizeof(buffer));
	line = (char *)malloc((sizeof(char) * (bytesRead) + 1));
	ft_memcpy(line, buffer, bytesRead);
	line[bytesRead] = '\0';

	return line;
	
}

