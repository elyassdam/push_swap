/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:06:05 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/24 23:07:01 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*int main()
{
	char str[] = "hello, WORLD!";
	int i = 0;

	printf("Cadena original: %s\n", str);

	while (str[i] != '\0')
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}

	printf("Cadena después de tolower: %s\n", str);

	return 0;
}*/