/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:15:12 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/27 13:24:09 by yael-you         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
    int len;
     
    len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (unsigned char)c)
			return ((char *)(&s[len]));
		
        len--;
	}

	return (NULL);
}
/*
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	const char	str[] = "Hello, World!";
	char		*result;

	result = ft_strrchr(str, 'j');
	if (result)
		printf("Last 'o' found at: %s\n", result);
	return (0);
}
*/