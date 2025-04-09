/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:25:45 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/27 02:06:51 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (c - 32);
	return (c);
}
/*int main()
{
	char str[] = "Hello, World!";
	int i = 0;

	printf("Cadena original: %s\n", str);

	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}

	printf("Cadena después de toupper: %s\n", str);

	return 0;
}*/