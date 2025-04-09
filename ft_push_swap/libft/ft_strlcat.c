/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:02:18 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/24 23:00:29 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_l;
	unsigned int	dest_l;

	i = 0;
	src_l = 0;
	dest_l = 0;
	while (dest[dest_l] != '\0')
		dest_l ++;
	while (src[src_l] != '\0')
		src_l ++;
	if (size <= dest_l)
		return (size + src_l);
	while (src[i] != '\0' && (dest_l + i + 1) < size)
	{
		dest[dest_l + i] = src[i];
		i ++;
	}
	dest[dest_l + i] = '\0';
	return (dest_l + src_l);
}
/*
//#include <stdio.h>
int main(void)
{
	char	d[9]="Hola";
	char	s[]="M";

	unsigned int res;
	res = ft_strlcat(d,s,9);
	printf("%d",res);
	printf("%s",d);

}*/