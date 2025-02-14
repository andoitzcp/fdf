/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2parray.c                                :+:    :+: :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: andoitzcp <andoitzcp@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:01:30 by andoitzcp         #+#    #+#             */
/*   Updated: 2025/02/14 02:02:22 by andoitzcp   ########  ###                */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free2parray(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
