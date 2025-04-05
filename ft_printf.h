/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vakande <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 09:51:06 by vakande           #+#    #+#             */
/*   Updated: 2025/04/04 14:56:52 by vakande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#	define FT_PRINTF_H

#	include <stdarg.h>
#	include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_formats(va_list args, const char letter);
int	ft_putchar(char c);

#endif
