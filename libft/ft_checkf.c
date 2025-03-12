/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 08:26:03 by fepennar          #+#    #+#             */
/*   Updated: 2025/02/11 17:30:28 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_checkf(char c, va_list args, int *count)
{
	if (c == 's')
		ft_putstr_c(args, count);
	else if (c == 'c')
		ft_putchar_c(va_arg(args, int), count);
	else if (c == 'd' || c == 'i')
		ft_putint_c(va_arg(args, int), count);
	else if (c == 'u')
		ft_putuint_c(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_puthex_c(va_arg(args, unsigned int), count, 'x');
	else if (c == 'X')
		ft_puthex_c(va_arg(args, unsigned int), count, 'X');
	else if (c == 'p')
		ft_pointer_c(va_arg(args, uintptr_t), count);
	else if (c == '%')
		ft_putchar_c('%', count);
}
