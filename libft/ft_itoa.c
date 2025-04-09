/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:00:00 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/30 13:12:44 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int s);
static char		*special(int n);

char	*ft_itoa(int n)
{
	size_t	len;
	char	*s;
	char	*start;

	len = ft_numlen(n);
    if (n == 0 || n  == -2147483648)
		return (special(n));
	s = (char *)malloc(len + 1);
    if (!s)
		return (NULL);
    start = s;
    if (n < 0)
	{
		*s = '-';
		n = -n;
	}
	s = s + (len - 1);
	while (n > 0)
	{
		*s-- = (n % 10) + '0';
		n = n / 10;
	}
	*(start + len) = '\0';
	return (start);
}

static char	*special(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (NULL);
}

static size_t	ft_numlen(int s)
{
	size_t	len;

	len = 0 ;
	if (s < 0)
		len ++;
	while (s)
	{
		s = s / 10;
		len ++;
	}
	return (len);
}

/*int main()
{
	// Prueba con el número 42
	int num = 42;
	char *str = ft_itoa(num);
	if (str)
	{
		printf("El número %d convertido a cadena es: %s\n", num, str);
		free(str); // Liberar la memoria cuando ya no la necesites
	}
	else
	{
		printf("Error al convertir el número %d.\n", num);
	}

	// Prueba con el número -42
	num = -42;
	str = ft_itoa(num);
	if (str)
	{
		printf("El número %d convertido a cadena es: %s\n", num, str);
		free(str);
	}
	else
	{
		printf("Error al convertir el número %d.\n", num);
	}

	// Prueba con el número 0
	num = 0;
	str = ft_itoa(num);
	if (str)
	{
		printf("El número %d convertido a cadena es: %s\n", num, str);
		free(str);
	}
	else
	{
		printf("Error al convertir el número %d.\n", num);
	}

	// Prueba con el número 2147483647
	num = 2147483647;
	str = ft_itoa(num);
	if (str)
	{
		printf("El número %d convertido a cadena es: %s\n", num, str);
		free(str);
	}
	else
	{
		printf("Error al convertir el número %d.\n", num);
	}

	// Prueba con el número -2147483648
	num = -2147483648;
	str = ft_itoa(num);
	if (str)
	{
		printf("El número %d convertido a cadena es: %s\n", num, str);
		free(str);
	}
	else
	{
		printf("Error al convertir el número %d.\n", num);
	}

	return 0;
}
*/