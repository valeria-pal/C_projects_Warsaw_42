/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:59:25 by vpaliash          #+#    #+#             */
/*   Updated: 2024/12/16 20:35:07 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_tokens(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static void	free_split(char **arr, int i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
}

static char	**fill_tokens(const char *s, char c, char **arr)
{
	char	*start;
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			arr[i] = (char *)malloc((s - start + 1) * sizeof(char));
			if (!arr[i])
				return (free_split(arr, i), NULL);
			ft_strlcpy(arr[i], start, s - start + 1);
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		token_count;
	char	**arr;

	if (!s)
		return (NULL);
	token_count = ft_count_tokens(s, c);
	arr = (char **)malloc((token_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!fill_tokens(s, c, arr))
		return (NULL);
	return (arr);
}
