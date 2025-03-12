/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:53:12 by fepennar          #+#    #+#             */
/*   Updated: 2025/01/10 14:03:51 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuint_c(unsigned int nb, int *count)
{
	unsigned long long int	nbr;

	nbr = (unsigned long long int)nb;
	ft_putnbr_base((unsigned long long int)nbr, DEC, count);
}
