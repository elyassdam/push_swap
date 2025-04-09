/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:20:16 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/28 00:52:49 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*s2_start;
	const char	*start;
	const char	*end;
	char		*s2;

	if (!s1 || !set)
		return (NULL);
	if (*set == '\0')
		return (ft_strdup(s1));
	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (start <= end && in_set(*start, set))
		start ++;
	while (end >= start && in_set(*end, set))
		end --;
	s2_start = (char *) malloc ((end - start + 1) + 1);
	if ((!s2_start))
		return (NULL);
	s2 = s2_start;
	while (start <= end)
		*s2 ++ = *start ++;
	*s2 = '\0';
	return (s2_start);
}

/*
int	main(void)
{
	char	*s1 = "  ***hello world***  ";
	char	*set = " *";
	char	*result;

	result = ft_strtrim(s1, set);
	if (result)
	{
		printf("Trimmed: '%s'\n", result);
		free(result);
	}
	return (0);
}
*/