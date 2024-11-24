/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:57:22 by salam             #+#    #+#             */
/*   Updated: 2024/11/24 19:21:54 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		if (n == 0)
			return (len);
		n = -n;
	}
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_is_special(void)
{
	char	*str;

	str = (char *)malloc(12 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

static void	ft_stritoa(char *str, int n, size_t len)
{
	size_t	i;

	i = len - 1;
	str[len] = '\0';
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	while (n)
	{
		str[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
// convert from int to ascii.
{
	char		*str;
	size_t		len;

	if (n == 0)
	{
		str = (char *)malloc(2 * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n == -2147483648)
		return (ft_is_special());
	len = ft_intlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_stritoa(str, n, len);
	return (str);
}
