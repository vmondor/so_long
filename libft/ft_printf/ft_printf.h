/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:54:51 by vmondor           #+#    #+#             */
/*   Updated: 2023/12/08 14:36:36 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putnbr_u(unsigned int nb);
int	ft_putnbr_base(unsigned long long nb, char *base);
int	ft_pointer(unsigned long long nb, char *base);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printf(const char *format, ...);

#endif