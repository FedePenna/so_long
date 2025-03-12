/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepennar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:52:43 by fepennar          #+#    #+#             */
/*   Updated: 2024/12/19 20:21:20 by fepennar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_lenght(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	num;

	len = check_lenght(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	num = n;
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[len] = (num % 10) + 48;
		num = num / 10;
		len--;
	}
	return (str);
}
/*
int main(void)
{
    int test[] = {0, -1, 123, -123, 2147483647, -2147483648};
    size_t lung = sizeof(test) / sizeof(test[0]);
    size_t i = 0;

    {
        int counter = test[i];
    	char *result = ft_itoa(counter);
		if (result)
        {
            printf("Numero: %d -> Stringa: \"%s\"\n", counter, result);
			free(result);
        }
        else
        {
printf("Numero: %d -> Errore di allocazione della memoria!\n", counter);
        }
	i++;
    }

    return 0;
}
*/
