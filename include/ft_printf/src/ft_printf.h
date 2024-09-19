/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:17:23 by acampo-p          #+#    #+#             */
/*   Updated: 2023/01/18 15:20:54 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
char	*ft_itoh(unsigned long n);
size_t	ft_putptr(void *ptr);
size_t	ft_putstr(char *s, char f);
size_t	ft_putchar(int c);
size_t	ft_putuprhex(unsigned int ui);
size_t	ft_putlwrhex(unsigned int ui);
size_t	ft_putint(int n);
size_t	ft_putdec(int n);
size_t	ft_putuni(unsigned int n);
int		ft_flaghub(char flag, va_list arg);

#endif
