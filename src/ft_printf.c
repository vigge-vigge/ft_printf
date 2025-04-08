/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vakande <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 10:09:14 by vakande           #+#    #+#             */
/*   Updated: 2025/04/08 14:58:16 by vakande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
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
	else if (letter == '%')
		length += ft_printpercent();
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_formats(args, str[i + 1]);
			i += 2;
		}
		else
		{
			print_len += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
	return (print_len);
}
