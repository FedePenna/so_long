/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:52:46 by fepennar          #+#    #+#             */
/*   Updated: 2025/01/10 12:56:25 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putint_c(int nb, int *count)
{
	long long int	nbr;

	nbr = (long long int)nb;
	if (nbr < 0)
	{
		ft_putchar_c('-', count);
		nbr = -nbr;
	}
	ft_putnbr_base((unsigned long long int)nbr, DEC, count);
}
