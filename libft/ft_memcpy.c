/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:45:51 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/18 17:54:42 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void				*origdest;
	const unsigned char	*s;
	unsigned char		*d;

	origdest = dest;
	s = (const unsigned char *) src;
	d = (unsigned char *) dest;
	while (n--)
		*d++ = *s++;
	return (origdest);
}
/*
int	main()
{
	char str1 [] = "pognotte";
	char str2 [] = "pagnotte";
	ft_memcpy(str1, str2, 1);
	write (1, str1, 8);
}
*/
