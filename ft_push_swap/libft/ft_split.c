/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:39:27 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/30 12:47:57 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void free_split (char **subs)
{
	char **ptr;

	ptr = subs;
	while (*subs)
		free(*subs++);
	
	free(ptr);
}
static int	subs_count(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s ++;
		if (*s)
		{
			count ++;
			while (*s && *s != c)
				s ++;
		}
	}
	return (count);
}

static size_t	ft_sublen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && (*s != c))
	{
		len ++;
		s ++;
	}
	if (len == 0)
		return (0);
	return (len);
}


static int	sub_cpy(char **subs, const char **s, size_t len)
{
	char	*start;

	start = *subs;
	if (!start)
		return (0);
	while (len--)
		*start++ = *(*s)++;
	*start = '\0';
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**subs;
	char	**start;
	int		n;
	size_t	len;

	n = subs_count((char *)s, c);
	subs = malloc((n + 1) * sizeof(char *));
	if (!s || !subs)
		return (NULL);
	start = subs;
	while (*s)
	{
		while (*s == c)
			s ++;
		if (*s)
		{
			len = ft_sublen((char *)s, c);
			*subs = malloc(len + 1);
			if (!sub_cpy(subs, &s, len))
				return ((free_split(start)), (NULL));
			subs ++;
		}
	}
	return (*subs = NULL, (start));
}
/*
int main()
{
	char **result;
	int i;

	// Probar el código con un ejemplo
	result = ft_split("     Hello world   this is a test  ", ' ');
	if (result)
	{
		printf("Resultado:\n");
		for (i = 0; result[i]; i++)
		{
			printf("Subcadena %d: %s\n", i, result[i]);
			free(result[i]);  // Liberar cada subcadena
		}
		free(result);  // Liberar el arreglo de subcadenas
	}

	return 0;
}
int main(void)
{
	char **wordarr = ft_split("      ", ' ');
	int count = 0;
	if(wordarr == NULL)
	{
		return 0;
	}
	while (wordarr[count])
	{
		printf("%s\n", wordarr[count++]);
	}
	free_all(wordarr);
	return (0);
}
*/