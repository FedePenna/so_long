/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:53:18 by fepennar          #+#    #+#             */
/*   Updated: 2025/01/10 11:52:24 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lens(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(unsigned long int nb, char *base, int *count)
{
	size_t	len;

	len = ft_lens(base);
	if (nb >= len)
		ft_putnbr_base(nb / len, base, count);
	ft_putchar_c(base[nb % len], count);
}
