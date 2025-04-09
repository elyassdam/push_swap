/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:52:10 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/29 13:49:01 by yael-you         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;

	a = (unsigned char *) s;
	while (n-- > 0)
	{
		if (*a == (unsigned char)c)
			return (a);
		a ++;
	}
	return (NULL);
}
/* #include <stdio.h>

int main() {
    char str[] = "Hola, Mundo!";
    char *result = ft_memchr(str, 'M', 15);  

    if (result)
        printf("Encontrado: %c\n", *result);
        printf("No encontrado\n");

    return 0;
} */
