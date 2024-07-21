/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:30:34 by yunozdem          #+#    #+#             */
/*   Updated: 2024/02/23 20:07:18 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(const char *s, va_list arg, int i)
{
	int	len;

	len = 0;
	if (s[i] == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (s[i] == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (s[i] == 'd')
		len += ft_putnbr(va_arg(arg, int));
	else if (s[i] == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else if (s[i] == 'u')
		len += ft_putnbr_u(va_arg(arg, unsigned int));
	else if (s[i] == '%')
		len += ft_putchar('%');
	else if (s[i] == 'x')
		len += ft_print_hex(va_arg(arg, unsigned int), 'x');
	else if (s[i] == 'X')
		len += ft_print_hex(va_arg(arg, unsigned int), 'X');
	else if (s[i] == 'p')
		len += ft_print_addr(va_arg(arg, unsigned long));
	return (len);
}
