/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:44:48 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/30 13:09:59 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	sizem;
	char	*c;

	sizem = ft_strlen(s);
	c = (char *)malloc(sizem + 1);
	if (!c)
		return (NULL);
	while (*s)
	{
		*c = *s ;
		s ++;
		c ++;
	}
	*c = '\0';
	return (c - sizem);
}
