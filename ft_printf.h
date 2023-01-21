/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:33:41 by gcozigon          #+#    #+#             */
/*   Updated: 2022/11/30 03:06:49 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define BASE_XX "0123456789abcdef"
# define BASE_X "0123456789ABCDEF"

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nbr, int *count);
int	ft_sort(char c, va_list *args);
int	ft_printf(const char *format, ...);
int	ft_putnbr_u(unsigned int nbr);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putnbr_base_p(unsigned long int nbr, char *base);

#endif
