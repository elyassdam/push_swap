/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:01:11 by yael-you          #+#    #+#             */
/*   Updated: 2025/04/10 14:49:40 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_converter(char format, va_list args, int *count)
{
	if (format == 'c')
		ft_putchar((char)va_arg(args, int), (int *)count++);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (format == 'p')
		ft_ptr(args, count);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (format == 'u')
		ft_putnbru((unsigned int)va_arg(args, unsigned int), count);
	else if (format == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", count);
	else if (format == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", count);
	else if (format == '%')
		ft_putchar('%', count);
	return (0);
}
