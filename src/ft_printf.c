/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vakande <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 10:09:14 by vakande           #+#    #+#             */
/*   Updated: 2025/04/09 19:05:58 by vakande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdint.h>

int	ft_formats(va_list args, const char letter)
{
	int	length;

	length = 0;
	if (letter == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (letter == 's')
		length += ft_printstr(va_arg(args, char *));
	else if (letter == 'd' || letter == 'i')
		length += ft_putnbr(va_arg(args, int));
	else if (letter == 'p')
		length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (letter == 'u')
		length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (letter == 'x')
		length += ft_print_hex(va_arg(args, unsigned int), letter);
	else if (letter == 'X')
		length += ft_print_hex(va_arg(args, unsigned int), letter);
	else if (letter == '%')
		length += ft_printpercent();
	else
		return (-1);
	if (length < 0)
		return (-1);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	if (!str)
		return (-1);
	va_start(args, str);
	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
			len += ft_formats(args, str[++i]);
		else
			len += ft_putchar(str[i]);
		if (len == -1)
			break ;
	}
	va_end(args);
	if (len == -1)
		return (-1);
	return (len);
}
