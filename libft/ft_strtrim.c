/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:47:16 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/16 16:36:58 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *str, const char *sep)
{
	size_t	len;
	size_t	i;
	char	*mstr;

	if (!str || !sep)
		return (NULL);
	len = ft_strlen(str) - 1;
	i = 0;
	while (ft_strchr(sep, str[i]))
		i++;
	while (ft_strchr(sep, str[len]))
		len--;
	mstr = ft_substr(str, i, len - i + 1);
	if (!str)
		return (NULL);
	return (mstr);
}
/*
int	main()
{
	char const *str = "-----Ciao--Sono--Un--Ritardato-----";
	char const *sep = "-";
	printf("%s", ft_strtrim(str, sep));
}
*/
