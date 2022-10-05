/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:59:10 by jtanner           #+#    #+#             */
/*   Updated: 2022/09/01 16:49:38 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "keys.h"

typedef struct s_image
{
	void	*image;
	char	*data;
	int		line_bytes;
	int		pix_bits;
	int		endian;
	int		color;
	int		end;
}				t_image;

typedef struct s_mouse
{
	int		state;
	int		x;
	int		y;
}				t_mouse;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct s_mlx
{
	void	*init;
	void	*win;
}				t_mlx;

typedef struct s_fract
{
	int		fract;
	int		iteration;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
}				t_fract;

typedef struct s_fractol
{
	t_image	image;
	t_mouse	mouse;
	t_color	color;
	t_mlx	mlx;
	t_fract	fract;
}				t_fractol;

int		main(int argc, char **argv);
void	startfract(t_fractol *f);
void	draw(t_fractol *f, int x, int y, int color);
void	setfract(t_fractol *f);
int		rgbtoint(double r, double g, double b);
void	error(void);
int		fcheck(char *word);
int		instruction(void *param);
void	move(int key, t_fractol *f);
void	zoom(t_fractol *f, double z);
int		mouseevent(int mouse, int x, int y, t_fractol *f);
int		keyevent(int key, t_fractol *f);
int		mandelbrot(t_fractol *f, double cr, double ci);
int		julia(t_fractol *f, double zr, double zi);
void	draw_fractal(t_fractol *f, int c);
#endif
