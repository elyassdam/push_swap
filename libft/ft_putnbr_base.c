/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:31:12 by yael-you          #+#    #+#             */
/*   Updated: 2025/04/10 14:47:45 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned long n, char *base, int *count)
{
	if (n == 0)
	{
		ft_putchar('0', count);
		return ;
	}
	if (n >= 16)
		ft_putnbr_base(n / 16, base, count);
	ft_putchar(*(base + (n % 16)), count);
}
