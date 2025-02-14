/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoi.c                                       :+:    :+: :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: andoitzcp <andoitzcp@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:47:08 by andoitzcp         #+#    #+#             */
/*   Updated: 2025/02/14 02:00:18 by andoitzcp   ########  ###                */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkinput(char *hex)
{
	if (!hex)
		return (0);
	if (ft_tolower(hex[0]) != '0' && ft_tolower(hex[1]) != 'x')
		return (perror("Not a valid hexadecimal string"), 0);
}

int	ft_xtoi(char *hex)
{
	int		i;
	int		j;
	int		x;
	char	base[17];

	if (ft_checkinput == 0)
		return (0);
	memcpy(base, "0123456789abcdef", 17);
	i = 2;
	x = 0;
	while (hex[i] != '\0')
	{
		x *= 16;
		j = 0;
		while (ft_tolower(hex[i]) != base[j])
		{
			if (base[j] == '\0')
				return (0);
			j++;
		}
		x += j;
		i++;
	}
	return (x);
}
