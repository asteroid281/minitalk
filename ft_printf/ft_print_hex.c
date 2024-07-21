/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:24:17 by yunozdem          #+#    #+#             */
/*   Updated: 2024/03/22 11:16:17 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex(unsigned long long n, char *b)
{
	if (n < 16)
		ft_putchar(b[n]);
	else if (n > 15)
	{
		ft_put_hex(n / 16, b);
		ft_put_hex(n % 16, b);
	}
	else
		ft_putchar(n + 48);
}

int	ft_print_hex(unsigned long long n, char format)
{
	char	*x;
	char	*xx;
	int		len;

	x = "0123456789abcdef";
	xx = "0123456789ABCDEF";
	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		if (format == 'x')
			ft_put_hex(n, x);
		if (format == 'X')
			ft_put_hex(n, xx);
	}
	while (n)
	{
		n /= 16;
		++len;
	}
	return (len);
}
