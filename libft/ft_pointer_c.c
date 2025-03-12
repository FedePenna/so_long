/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:35:09 by fepennar          #+#    #+#             */
/*   Updated: 2025/01/10 16:09:32 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_point_null(void *ptr, int *count)
{
	if (!ptr)
	{
		ft_putstr("(nil)");
		*count += 5;
		return (1);
	}
	return (0);
}

void	ft_pointer_c(uintptr_t nb, int *count)
{
	if (ft_point_null((void *)nb, count) == 1)
		return ;
	else
	{
		ft_putchar_c('0', count);
		ft_putchar_c('x', count);
	}
	ft_putnbr_base((unsigned long long)nb, HEX_LWC, count);
}
