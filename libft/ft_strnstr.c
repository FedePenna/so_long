/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:59:38 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/19 19:07:34 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	si;

	i = 0;
	si = 0;
	if (needle == NULL || needle[0] == '\0')
		return ((char *)hay);
	while (i < len && hay[i])
	{
		if (hay[i] == needle[si])
		{
			while (hay[i + si] == needle[si] && i + si < len)
			{
				if (needle[si + 1] == '\0')
					return ((char *)&hay[i]);
				si++;
			}
			si = 0;
		}
		i++;
	}
	return (NULL);
}
/*
int main()
{
	char msg1[] = "ciao fede, sei un ritardato";
	char msg2[] = "fede";
	printf("%s\n", ft_strnstr(msg1, msg2, 99));
}
*/
