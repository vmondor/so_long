/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:54:32 by vmondor           #+#    #+#             */
/*   Updated: 2023/12/08 14:25:05 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int	ft_flag(char c)
{
	if (c == 'c' || c == 's' || c == 'p')
		return (1);
	if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	if (c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_control_flag(va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(arg, int));
	if (c == '%')
		len += ft_putchar('%');
	if (c == 's')
		len += ft_putstr(va_arg(arg, char *));
	if (c == 'p')
		len += ft_pointer(va_arg(arg, unsigned long long), "0123456789abcdef");
	if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(arg, int));
	if (c == 'u')
		len += ft_putnbr_u(va_arg(arg, unsigned int));
	if (c == 'x')
		len += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	if (c == 'X')
		len += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		i;

	va_start(arg, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_flag(format[i + 1]))
		{
			len += ft_control_flag(arg, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
