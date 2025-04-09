/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:10:49 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/29 14:12:05 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				res;

	a = (unsigned char *) s1;
	b = (unsigned char *) s2;
	res = 0;
	while (n--)
	{
		if (*a != *b)
		{
			res = *a - *b;
			return (res);
		}
		a ++;
		b ++;
	}
	return (0);
}

/*
int main()
{
	char str1[] = "Hello, world!";
	char str2[] = "Hello, world!";
	char str3[] = "Hello, there!";

	int result1 = ft_memcmp(str1, str2, 13);
	printf("ft_memcmp(str1, str2, 13) = %d\n", result1);

	int result2 = ft_memcmp(str1, str3, 13);
	printf("ft_memcmp(str1, str3, 13) = %d\n", result2);

	int result3 = ft_memcmp(str1, str3, 6);
	printf("ft_memcmp(str1, str3, 6) = %d\n", result3);

	return 0;
}
*/