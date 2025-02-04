/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 02:21:26 by ael-hadj          #+#    #+#             */
/*   Updated: 2024/12/16 02:21:28 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_rest(const char *format, va_list args)
{
	int	count;

	count = 0;
	{
		if (*format == '%')
			count += ft_putchar('%');
		if (*format == 'c')
			count += ft_putchar(va_arg(args, int));
		if (*format == 's')
			count += ft_putstr(va_arg(args, char *));
		if (*format == 'd' || *format == 'i')
			count += ft_putnbr(va_arg(args, int));
		if (*format == 'u')
			count += ft_putunsigned(va_arg(args, unsigned int));
		if (*format == 'p')
			count += ft_put_pointer(va_arg(args, unsigned long));
		if (*format == 'x')
			count += ft_puthex(va_arg(args, unsigned int), 0);
		if (*format == 'X')
			count += ft_puthex(va_arg(args, unsigned int), 1);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_printf_rest(format + i, args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
