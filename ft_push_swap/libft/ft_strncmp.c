/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:11:51 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/27 14:09:33 by yael-you         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	res;

	res = 0;
    	if (s1 == NULL && s2 == NULL)
            return (res);
	while (n-- && (*s1 != '\0' ||  *s2 != '\0'))
	{
		if (*s1 != *s2)
		{
			res = (unsigned char)*s1 - (unsigned char)*s2;
			return (res);
            
		}
		s1 ++;
		s2 ++;
	}
	return (res);
}
