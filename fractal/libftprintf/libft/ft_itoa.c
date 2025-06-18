/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpaliash <vpaliash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:01:12 by vpaliash          #+#    #+#             */
/*   Updated: 2024/12/16 19:52:47 by vpaliash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_count_digits(int *counter, long long int nbr)
{
	long long int	temp;

	temp = nbr;
	if (nbr < 0)
	{
		nbr = -nbr;
		(*counter)++;
	}
	if (nbr == 0)
	{
		*counter = 1;
		return ;
	}
	temp = nbr;
	while (temp > 0)
	{
		temp = temp / 10;
		(*counter)++;
	}
}

static void	ft_fill_arr(char *arr, int i, long long int nbr)
{
	if (nbr == 0)
	{
		arr[0] = '0';
		return ;
	}
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		arr[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	long long int	nbr;
	char			*arr;
	int				counter;
	int				i;

	nbr = n;
	counter = 0;
	ft_count_digits(&counter, nbr);
	arr = (char *)malloc((counter + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	arr[counter] = '\0';
	if (n < 0)
		arr[0] = '-';
	i = counter - 1;
	ft_fill_arr(arr, i, nbr);
	return (arr);
}
