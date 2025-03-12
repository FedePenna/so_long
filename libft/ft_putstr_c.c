/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:39:58 by fepennar          #+#    #+#             */
/*   Updated: 2025/01/10 13:03:27 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_c(va_list args, int *count)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar_c(*str, count);
		str++;
	}
}
