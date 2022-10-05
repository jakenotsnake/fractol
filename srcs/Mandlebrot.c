/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:16:59 by jtanner           #+#    #+#             */
/*   Updated: 2022/09/01 16:44:39 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/fractol.h"
#include "../includes/keys.h"

int	mandelbrot(t_fractol *f, double cr, double ci)
{
	int		n;	
	double	zr;	
	double	zi;	
	double	tmp;
	int		is_in_set;

	zr = 0;
	zi = 0;
	n = -1;
	is_in_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			is_in_set = 0;
			break ;
		}
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
	}
	if (is_in_set == 1)
		return (f->image.end);
	else
		return ((f->image.color - f->image.end) * n / 80 + f->image.end);
}

int	bar(t_fractol *f, double cr, double ci, int c)
{
	double	n;	
	double	zr;	
	double	zi;	

	zr = 0;
	zi = 0;
	n = -1;
	c = -1;
	while (++c < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			n = 0;
			break ;
		}
		n = -zi * (5 * ((zr * zr) * (zr * zr)) - 10 * ((zr * zr)
					* (zi * zi)) + ((zi * zi) * (zi * zi))) + ci;
		zr = zr * (((zr * zr) * (zr * zr)) - 10 * ((zr * zr)
					* (zi * zi)) + 5 * ((zi * zi) * (zi * zi))) + cr;
		zi = n;
	}
	if (n != 0)
		return (f->image.end);
	else
		return ((f->image.color - f->image.end) * c / 80 + f->image.end);
}

int	julia(t_fractol *f, double zr, double zi)
{
	int		n;	
	double	tmp;	
	int		is_in_set;
	int		color;

	n = -1;
	is_in_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			is_in_set = 0;
			break ;
		}
		tmp = 2 * zr * zi + f->fract.ki;
		zr = zr * zr - zi * zi + f->fract.kr;
		zi = tmp;
	}
	if (is_in_set == 1)
		return (f->image.end);
	else
		color = ((f->image.color - f->image.end) * n
				/ MAX_ITERATIONS + f->image.end);
	return (color);
}

void	draw_fractal(t_fractol *f, int c)
{
	int		x;
	int		y;
	double	pr;
	double	pi;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = f->fract.min_r + (double)x * (f->fract.max_r
					- f->fract.min_r) / WIDTH;
			pi = f->fract.min_i + (double)y * (f->fract.max_i
					- f->fract.min_i) / HEIGHT;
			if (f->fract.fract == 1)
				c = mandelbrot(f, pr, pi);
			else if (f->fract.fract == 2)
				c = julia(f, pr, pi);
			else if (f->fract.fract == 3)
				c = bar(f, pr, pi, c);
			draw(f, x, y, c);
		}
	}
	mlx_put_image_to_window(f->mlx.init, f->mlx.win, f->image.image, 0, 0);
}
