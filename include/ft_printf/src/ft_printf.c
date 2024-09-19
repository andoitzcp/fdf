/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:31:41 by acampo-p          #+#    #+#             */
/*   Updated: 2023/01/19 09:42:11 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flaghub(char flag, va_list arg)
{
	if (flag == 'c')
		return (ft_putchar(va_arg(arg, unsigned int)));
	else if (flag == 's')
		return (ft_putstr(va_arg(arg, char *), 's'));
	else if (flag == 'p')
		return (ft_putptr(va_arg(arg, char *)));
	else if (flag == 'd')
		return (ft_putdec(va_arg(arg, int)));
	else if (flag == 'i')
		return (ft_putint(va_arg(arg, int)));
	else if (flag == 'u')
		return (ft_putuni(va_arg(arg, unsigned int)));
	else if (flag == 'X')
		return (ft_putuprhex(va_arg(arg, unsigned int)));
	else if (flag == 'x')
		return (ft_putlwrhex(va_arg(arg, unsigned int)));
	else if (flag == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		char_prntd;
	int		tot_prntd;

	char_prntd = 0;
	tot_prntd = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			char_prntd = ft_flaghub(*str, arg);
			if (char_prntd == -1)
				return (-1);
			tot_prntd += char_prntd;
		}
		else
			tot_prntd += ft_putchar(*str);
		str++;
	}
	va_end(arg);
	return (tot_prntd);
}
