/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:18:19 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/27 01:59:38 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned
int, char))
{
	char	*c;
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	c = malloc(sizeof(char) * len +1);
	if (!c)
		return (NULL);
	while (s[i])
	{
		c[i] = f(i, s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}

/*
int main()
{
	char (*f)(unsigned int n, char c);
	f = f1;
	char const *s = "Hola";
printf ("%s",ft_strmapi(s,f));
	
}static char f1(unsigned int n, char c)
{
	if (n || c)
		c = c+2;
	return c;
}
*/