/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                     	            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 00:38:36 by vmondor           #+#    #+#             */
/*   Updated: 2023/12/08 14:23:31 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = nb * -1;
	}
	if (nb > 9)
	{	
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
	{
		count += ft_putchar(nb + '0');
	}
	return (count);
}

int	ft_putnbr_u(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{	
		count += ft_putnbr_u(nb / 10);
		count += ft_putnbr_u(nb % 10);
	}
	else
	{
		count += ft_putchar(nb + '0');
	}
	return (count);
}

int	ft_putnbr_base(unsigned long long nb, char *base)
{
	int				count;

	count = 0;
	if (nb > 16 - 1)
	{	
		count += ft_putnbr_base(nb / 16, base);
		count += ft_putnbr_base(nb % 16, base);
	}
	else
	{
		count += ft_putchar(base[nb]);
	}
	return (count);
}

int	ft_pointer(unsigned long long nb, char *base)
{
	int				count;

	count = 0;
	if (!nb)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	else
		count += ft_putstr("0x");
	if (nb > 16 - 1)
	{	
		count += ft_putnbr_base(nb / 16, base);
		count += ft_putnbr_base(nb % 16, base);
	}
	else
		count += ft_putchar(base[nb]);
	return (count);
}
