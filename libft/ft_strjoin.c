/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:36:10 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/27 01:56:20 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*s3_start;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = (char *) malloc (len1 + len2 + 1);
	if (!s3)
		return (NULL);
	s3_start = s3;
	while (*s1)
	{
		*s3 = *s1;
		s1 ++;
		s3 ++;
	}
	while (*s2)
	{
		*s3 = *s2;
		s2 ++;
		s3 ++;
	}
	*s3 = '\0';
	return (s3_start);
}
