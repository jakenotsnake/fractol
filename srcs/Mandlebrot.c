/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandlebrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:16:59 by jtanner           #+#    #+#             */
/*   Updated: 2022/08/22 16:44:49 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

void	mandelbrot(t_fractol *f, int x, int y, double cr, double ci)
{
	int		n;	// Number of iterations
	double	zr;	// Real part of Z
	double	zi;	// Imaginary part of Z
	double	tmp;	// Temporary variable
	// Variable to determine if a number is in the set or not:
	int	is_in_set; 

	zr = 0;
	zi = 0;
	n = -1;
	is_in_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		// As long as we're not at the maximum number of iterations,
		// we iterate
		if ((zr * zr + zi * zi) > 4.0)
		{
			// If the absolute value of Z exceeds 2
			// (zr * zr + zi * zi) > 4.0 == sqrt(zr * zr + zi * zi) > 2
			is_in_set = 0;
			// We flag that this number tends toward infinity, 
			// and is therefore not part of the set
			// and we stop iterating
			break ;
		}
		// Calculate the Mandelbrot formula for the next iteration
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
	}
	// If the number is part of the Mandelbrot set,
	// set the pixel to black, otherwise to white
	if (is_in_set == 1)
		draw(f, x, y, 0x000000);
	else
		draw(f, x, y, 0xFFFFFF);
}

void	julia(t_fractol *f, int x, int y, double cr, double ci)
{
	int		n;	// Number of iterations
	double	zr;	// Real part of Z
	double	zi;	// Imaginary part of Z
	double	tmp;	// Temporary variable
	// Variable to determine if a number is in the set or not:
	int	is_in_set; 

	zr = 0;
	zi = 0;
	n = -1;
	is_in_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		// As long as we're not at the maximum number of iterations,
		// we iterate
		if ((zr * zr + zi * zi) > 4.0)
		{
			// If the absolute value of Z exceeds 2
			// (zr * zr + zi * zi) > 4.0 == sqrt(zr * zr + zi * zi) > 2
			is_in_set = 0;
			// We flag that this number tends toward infinity, 
			// and is therefore not part of the set
			// and we stop iterating
			break ;
		}
		// Calculate the Mandelbrot formula for the next iteration
		tmp = 2 * zr * zi + f->frac.ki;
		zr = zr * zr - zi * zi + f->fract.kr;
		zi = tmp;
	}
	// If the number is part of the Mandelbrot set,
	// set the pixel to black, otherwise to white
	if (is_in_set == 1)
		draw(f, x, y, 0x000000);
	else
		draw(f, x, y, 0xFFFFFF);
}


}

void	draw_fractal(t_fractol *f)
{
	// x and y coordinates of the pixel:
	int	x; // column
	int	y; // line
	// to map the x and y coordinates of the pixel to a
	// complex number:
	double	pr; // real part of the complex number of the pixel
	double	pi; // imaginary part of the complex number of the pixel

	// Loop over each line and column of the window
	// to check each pixels
	y = -1;
	while (++y < HEIGHT) // line loop
	{
		x = -1;
		while (++x < WIDTH) // column loop
		{
			// Find pixel[x, y]'s corresponding complex number
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;
			// Evaluate it and set this pixel's color
			mandelbrot(f, x, y, pr, pi);
		}
	}
}


