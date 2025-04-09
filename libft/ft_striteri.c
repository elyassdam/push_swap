/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:25:43 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/27 01:55:53 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int,
char*))
{
	int	i;

	i = 0;
	while (s[i] != '\0' )
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int main()
{
	void (*f)(unsigned int n, char c);
	f = f1;
	char  *s = "Hola";
	printf ("%p",&s);
	ft_striteri(s,f);
	printf ("%p",&s);
}
static void f1(unsigned int n, char *c)
{
	if (n || c)
		c = c+2;
}*/