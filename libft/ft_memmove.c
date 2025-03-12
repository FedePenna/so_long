/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:05:06 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/17 15:41:00 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*tpd;
	unsigned char	*tps;

	i = 0;
	tpd = (unsigned char *)dest;
	tps = (unsigned char *)src;
	if (!tpd && !tps)
		return (0);
	if (dest <= src)
		while (n--)
			*tpd++ = *tps++;
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			tpd[i] = tps[i];
			i--;
		}
	}
	return (dest);
}
/*
int	main()
{
	char	src[] = "bat 21";
	char	dest[21];
	ft_memmove(dest, src, 21);

}
*/
