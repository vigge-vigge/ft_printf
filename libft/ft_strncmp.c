/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vakande <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:52:46 by vakande           #+#    #+#             */
/*   Updated: 2025/01/22 14:21:19 by vakande          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		i++;
	}
	if (n > 0)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	else
	{
		return (0);
	}
}
