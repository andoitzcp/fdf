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
# define MIN_COLOR 0x00FFFFFF
# define MAX_COLOR 0x00000000

typedef struct s_node
{
    int x;
    int y;
    int z;
    int c;
    int carx;
    int cary;
    char is_printed;
    struct s_node *u;
    struct s_node *d;
    struct s_node *l;
    struct s_node *r;
} t_node;

typedef struct s_params
{
    unsigned int width;
    unsigned int heigh;
    unsigned int i;
    double angle;
    int xoffset;
    int yoffset;
} t_params;

typedef struct s_img
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_img;

typedef struct s_var
{
    void *mlx;
    void *win;
    t_img img;
    t_node **head;
    t_params *par;
    int canvas_mode;
} t_var;

// File parsing
t_node *ft_defpoint(int x, int y, char *param);
void ft_storeline(t_node **head, char **params);
t_node **ft_parsefile(char *s);

// Point manipulation
t_params *ft_setinitparams(t_node **head);
t_node *ft_defpoint(int x, int y, char *param);
t_node *ft_relocpoint(t_node *p, t_params *par, unsigned int mod);
t_node **ft_recalcgrid(t_node **head, t_params *par);

// Pixel printing
void ft_print_vector(t_var *var, t_node *a, t_node *b);
void ft_link_point(t_node *p, t_var *var);
void printgrid(t_node **head, t_var *var);

// Console debugging
void db_printpoint(t_node *p);
void db_printtest(t_node *p);
void db_printline(t_node *p);
void db_printmatrix(t_node **head);
void db_printparams(char **params);

#endif
