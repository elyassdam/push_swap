/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:07:13 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/29 15:23:40 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start,
size_t len)
{
	size_t	count;
	char	*c;
	
	if (!s)
		return NULL;
	if  (len > (ft_strlen(s)- start))
		len = ft_strlen(s)- start;
	if (start >= ft_strlen(s))
        return ft_strdup("");
	c = (char *)malloc(len + 1);
	if (!c)
		return (NULL);
	count = 0;
	s += start;
	while (*s && (len > count))
	{
		*c = *s;
		c ++;
		s ++;
		count ++;
	}
	*c = '\0';
	return (c - count);
}
