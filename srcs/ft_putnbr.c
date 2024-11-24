/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salam <salam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:59:01 by sbibers           #+#    #+#             */
/*   Updated: 2024/11/24 19:27:23 by salam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		putnbr(n);
	}
	else if (n > 9)
	{
		putnbr(n / 10);
		putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}
