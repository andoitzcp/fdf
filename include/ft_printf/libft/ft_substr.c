/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                     :+:    :+: :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:11:32 by acampo-p          #+#    #+#             */
/*   Updated: 2025/02/14 02:15:11 by andoitzcp   ########  ###                */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	sublen;

	if (start >= ft_strlen(s))
	{
		len = 0;
		start = 0;
	}
	sublen = ft_strlen(&s[start]);
	if (sublen < len)
		len = sublen;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, &s[start], len);
	str[len] = '\0';
	return (str);
}
