/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:07:52 by palefebv          #+#    #+#             */
/*   Updated: 2024/10/31 00:08:05 by palefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		len += ft_putnbr(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putunbr(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}

int	ft_puthex(unsigned long n, int uppercase)
{
	char	*hex;
	int		len;

	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, uppercase);
	len += ft_putchar(hex[n % 16]);
	return (len);
}

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				len;

	len = 0;
	addr = (unsigned long)ptr;
	if (addr == 0)
		return (ft_putstr("(nil)"));
	if (!addr)
		return (ft_putstr("0x0"));
	len += ft_putstr("0x");
	len += ft_puthex(addr, 0);
	return (len);
}
