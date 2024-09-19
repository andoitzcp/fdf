/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:42:25 by acampo-p          #+#    #+#             */
/*   Updated: 2022/12/14 13:56:50 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_gen(int n, unsigned int nbr, unsigned int dbase, size_t figs)
{
	char	*str;

	str = (char *)malloc((figs + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		str++;
	}
	while (dbase > 1)
	{
		*str = nbr / dbase + '0';
		nbr -= (*str - '0') * dbase;
		dbase /= 10;
		str++;
	}
	*str = nbr + '0';
	str++;
	*str = '\0';
	return (str - figs);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	unsigned int	dbase;
	size_t			figs;

	dbase = 1;
	figs = 1;
	if (n < 0)
	{
		nbr = -1 * n;
		figs++;
	}
	else
		nbr = n;
	while (nbr / dbase >= 10)
	{
		dbase *= 10;
		figs++;
	}
	return (str_gen(n, nbr, dbase, figs));
}
