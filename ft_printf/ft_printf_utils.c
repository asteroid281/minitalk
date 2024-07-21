/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:26:13 by yunozdem          #+#    #+#             */
/*   Updated: 2024/02/23 18:55:30 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[++i])
		write(1, &s[i], 1);
	return (i);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		len += ft_putnbr(n / 10);
	len += ft_putchar(n % 10 + 48);
	return (len);
}

int	ft_putnbr_u(unsigned long n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putnbr_u(n / 10);
	len += ft_putchar(n % 10 + 48);
	return (len);
}
