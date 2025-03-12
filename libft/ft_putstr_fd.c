/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:42:29 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/13 17:04:48 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
	{
		write (fd, str, 1);
		str++;
	}
}
/*
int	main()
{
	int	fd;
	char	*str = "iaopippo";

	fd = open("filetestfd", O_WRONLY);
	ft_putstr_fd(str, fd);
}
*/
