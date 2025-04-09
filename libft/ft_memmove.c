/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:48:02 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/29 14:15:03 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
    unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)src;
	b = (unsigned char *)dest;

	if ((b > a) && (b < (a + n)))
	{
		a += n - 1;
		b += n - 1;
		while (n --)
			*b-- = *a--;
	}
	else
	{
		while (n--)
			*b++ = *a++;
    }
	return (dest);
}
