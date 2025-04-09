/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:44:53 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/29 14:11:04 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	if (!dest && !src)
		return (NULL);
	a = (unsigned char *)src;
	b = (unsigned char *)dest;
	while (n--)
	{
		*b = *a;
		a ++;
		b ++;
	}
	return (dest);
}
/*#include <stdio.h>

int main() {
	size_t n = 5;
	while (n--) {
		printf("n: %zu\n", n);
	}
	printf("Bucle finalizado.\n");
	return 0;
}
*/