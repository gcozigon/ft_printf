/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:43:50 by gcozigon          #+#    #+#             */
/*   Updated: 2022/12/02 17:58:53 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	for_p(va_list *args)
{
	unsigned long	fff;

	fff = va_arg(*args, unsigned long);
	if (!fff)
		return (write(1, "(nil)", 5));
	else
		return (ft_putstr("0x") + ft_putnbr_base_p(fff, BASE_XX));
}

int	ft_sort(char c, va_list *args)
{
	int				count;

	count = 0;
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int), &count));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(*args, unsigned int), BASE_XX));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(*args, unsigned int), BASE_X));
	else if (c == 'p')
		return (for_p(&*args));
	else
		return (ft_putchar('%'));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		index;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	index = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			index += ft_sort(format[++i], &args);
		}
		else
			index += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (index);
}
