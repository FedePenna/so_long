/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:24:03 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/13 17:35:06 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int	n;

	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		n = nb % 10 + 48;
		write (fd, &n, 1);
	}
	else
	{
		n = nb + 48;
		write(fd, &n, 1);
	}
}
/*
int	main ()
{
	int	fd = open("filetestfd", O_WRONLY);
	ft_putnbr_fd(123, fd);
}
*/
