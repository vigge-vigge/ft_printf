/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vakande <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 09:51:06 by vakande           #+#    #+#             */
/*   Updated: 2025/04/08 14:59:32 by vakande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_formats(va_list args, const char letter);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_putnbr(int n);
int		ft_ptr_len(uintptr_t num);
void	ft_put_ptr(uintptr_t num);
int		ft_print_ptr(unsigned long long ptr);
int		ft_num_len(unsigned int num);
char	*ft_uitoa(unsigned int n);
int		ft_print_unsigned(unsigned int n);
int		ft_hex_len(unsigned int num);
void	ft_put_hex(unsigned int num, const char format);
int		ft_print_hex(unsigned int num, const char format);
int		ft_printpercent(void);

#endif
