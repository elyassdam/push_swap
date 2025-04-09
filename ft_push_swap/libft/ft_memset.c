/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:39:57 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/27 01:37:40 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n--)
	{
		*str = c;
		str ++;
	}
	return (s);
}

/*int main()
{
	char str[50] = "Hello, world!";
	
	printf("Antes de memset: %s\n", str);
	ft_memset(str, '*', 5);
	printf("Después de memset: %s\n", str);

	return 0;
}*/