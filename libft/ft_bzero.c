/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:47:20 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/11 16:00:04 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *r, size_t l)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)r;
	i = 0;
	while (i < l)
	{
		str[i] = '\0';
		i++;
	}
}
/*
int	main()
{
	char str[] = "ciao";
	ft_bzero(str, 2);
	write(1, str, 4);
	
}
*/
