/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:30:09 by gcozigon          #+#    #+#             */
/*   Updated: 2022/11/30 03:04:11 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
		index += ft_putchar(*str++);
	return (index);
}

int	ft_putnbr(int nbr, int *count)
{
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		*count += ft_putchar(45);
		nbr = nbr * -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, count);
	*count += ft_putchar((nbr % 10) + 48);
	return (*count);
}

int	ft_putnbr_u(unsigned int nbr)
{
	static int	index;

	index = 0;
	if (nbr < 10)
		index += ft_putchar(nbr + 48);
	else
	{
		ft_putnbr_u(nbr / 10);
		index += ft_putchar((nbr % 10) + 48);
	}
	return (index);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	static int	index;

	index = 0;
	if (nbr >= 16)
		ft_putnbr_base((nbr / 16), base);
	index += ft_putchar(base[nbr % 16]);
	return (index);
}

int	ft_putnbr_base_p(unsigned long int nbr, char *base)
{
	static int	index;

	index = 0;
	if (nbr >= 16)
		ft_putnbr_base_p((nbr / 16), base);
	index += ft_putchar(base[nbr % 16]);
	return (index);
}
