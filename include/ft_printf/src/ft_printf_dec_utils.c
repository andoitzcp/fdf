/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:52:51 by acampo-p          #+#    #+#             */
/*   Updated: 2023/01/18 17:03:28 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_figcalc(long n)
{
	unsigned int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itos(long n)
{
	char	*dec;
	char	*base;
	size_t	len;
	long	tmp;

	len = ft_figcalc(n);
	dec = (char *)ft_calloc(len + 1, sizeof(char));
	base = ft_strdup("0123456789");
	tmp = n;
	if (n < 0)
		n *= -1;
	while (len > 0)
	{
		dec[len - 1] = base[n % 10];
		n /= 10;
		len--;
	}
	if (tmp < 0)
		dec[0] = '-';
	free(base);
	return (dec);
}

size_t	ft_putint(int n)
{
	char	*int_str;
	size_t	len;

	int_str = ft_itos(n);
	len = ft_putstr(int_str, 'i');
	free(int_str);
	return (len);
}

size_t	ft_putdec(int n)
{
	char	*int_str;
	size_t	len;

	int_str = ft_itos(n);
	len = ft_putstr(int_str, 'd');
	free(int_str);
	return (len);
}

size_t	ft_putuni(unsigned int n)
{
	char	*int_str;
	size_t	len;

	int_str = ft_itos(n);
	len = ft_putstr(int_str, 'u');
	free(int_str);
	return (len);
}
