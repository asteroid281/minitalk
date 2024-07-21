/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:19:12 by yunozdem          #+#    #+#             */
/*   Updated: 2024/02/23 20:07:50 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_formats(const char *str, va_list arg, int i);
int	ft_putnbr(int n);
int	ft_putnbr_u(unsigned long n);
int	ft_print_hex(unsigned long long n, char format);
int	ft_print_addr(unsigned long long n);

#endif
