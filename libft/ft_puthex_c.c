/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:59:30 by fepennar          #+#    #+#             */
/*   Updated: 2025/01/09 18:20:23 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_c(unsigned int hexn, int *count, char upclwc)
{
	if (upclwc == 'x')
		ft_putnbr_base((unsigned long long)hexn, HEX_LWC, count);
	else if (upclwc == 'X')
		ft_putnbr_base((unsigned long long)hexn, HEX_UPC, count);
}
