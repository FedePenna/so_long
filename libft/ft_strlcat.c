/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:18:20 by fepennar          #+#    #+#             */
/*   Updated: 2025/02/11 17:10:07 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	srsz;

	i = 0;
	j = 0;
	srsz = ft_strlen(src);
	while (dest[i] != '\0' && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	return (i + srsz);
}
/*
int	main()
{
	char dest[] = "tesiditone";
//	char src[] = "42 42";
	printf("%zu \n", ft_strlcat(dest, NULL, 0));
}
*/
