/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:19:02 by acampo-p          #+#    #+#             */
/*   Updated: 2023/01/18 17:12:41 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoh(unsigned long n)
{
	unsigned int	len;
	unsigned long	tmp;
	char			*hex;
	char			*base;

	len = 0;
	tmp = n;
	if (n == 0)
		len++;
	while (tmp > 0)
	{
		tmp /= 16;
		len++;
	}
	hex = (char *)ft_calloc(len + 1, sizeof(char));
	base = ft_strdup("0123456789abcdefg");
	tmp = n;
	while (len > 0)
	{
		hex[len - 1] = base[tmp % 16];
		tmp /= 16;
		len--;
	}
	free(base);
	return (hex);
}

size_t	ft_putptr(void *ptr)
{
	char	*ptr_str;
	char	*aux;
	size_t	len;

	ptr_str = NULL;
	if (!ptr)
		ptr_str = ft_strdup("0x0");
	else
	{
		aux = ft_itoh((unsigned long) ptr);
		ptr_str = ft_strjoin("0x", aux);
		free(aux);
	}
	len = ft_putstr(ptr_str, 'p');
	free(ptr_str);
	return (len);
}

size_t	ft_putuprhex(unsigned int ui)
{
	char	*uphex_str;
	size_t	i;
	size_t	len;

	uphex_str = ft_itoh(ui);
	i = 0;
	while (uphex_str[i])
	{
		uphex_str[i] = ft_toupper(uphex_str[i]);
		i++;
	}
	len = ft_putstr(uphex_str, 'X');
	free(uphex_str);
	return (len);
}

size_t	ft_putlwrhex(unsigned int ui)
{
	char	*lwhex_str;
	size_t	len;

	lwhex_str = ft_itoh(ui);
	len = ft_putstr(lwhex_str, 'x');
	free(lwhex_str);
	return (len);
}
