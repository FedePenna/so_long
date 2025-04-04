/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:50:13 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/18 18:36:23 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*mstr;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	mstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!mstr)
		return (NULL);
	while (len)
	{
		mstr[i] = s[start];
		i++;
		start++;
		len--;
	}
	mstr[i] = '\0';
	return (mstr);
}
/*
int	main()
{
	char str[] = "hello world";
	char *dest;
	unsigned int	start;
	size_t	len;

        mstr = (char *)malloc(sizeof(char) * len + 1);
	start = 2;
	len = 5;
	dest = ft_substr(str, start, len);
	printf("la sottostringa e %s\n", dest);
	free(dest);
}
*/
