/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:22:26 by acampo-p          #+#    #+#             */
/*   Updated: 2024/09/16 11:38:15 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_FDF_H
# define FT_FDF_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "../include/minilibx-linux/mlx.h"
# include "../include/libft/libft.h"
# include "../include/ft_printf/src/ft_printf.h"

# define SCRN_WIDTH 1920
# define SCRN_HEIGH 1920

typedef struct s_node
{
    int x;
    int y;
    int z;
    int c;
    char is_printed;
    struct s_node *u;
    struct s_node *d;
    struct s_node *l;
    struct s_node *r;
} t_node;

t_node *ft_defpoint(int x, int y, char *param);
void ft_storeline(t_node **head, char **params);
void ft_parsefile(char *s);

void db_printpoint(t_node *p);
void db_printline(t_node *p);
void db_printmatrix(t_node **head);

#endif
