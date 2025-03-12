/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:01:29 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/16 09:57:46 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	while (*str)
	{
		write (fd, str, 1);
		str++;
	}
	write (fd, "\n", 1);
}
/*
int	main()
{
	int	fd;
	char	*str = "bassa terronia esplosa";

	fd = open("filetestfd", O_WRONLY);
	ft_putendl_fd(str, fd);
}
*/
