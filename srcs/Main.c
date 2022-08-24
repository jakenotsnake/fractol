/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:31:07 by jtanner           #+#    #+#             */
/*   Updated: 2022/08/22 19:22:43 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	main(int argc, char **argv)
{
		t_fractol f;

		if (argc == 2)
		{
			if (!(f = (t_fractol)malloc(sizeof(t_fractol))))
				error;
			f->fract.fract = fcheck(argv[1]);
			if (f->fract.fract == 0)
				instruction();
			f->mlx.init = mlx_init();
			f->mlx.win = mlx_new_window(f->mlx.init, WIDTH, HEIGHT, argv[1]);
			f->image.image = mlx_new_image(f->mlx.init, WIDTH, HEIGHT);
			f->image.data = mlx_get_data_addr(f->image.image, &f->image.pix_bits, &f->image.line_bytes, &f->image.endian)
			setfract(f);
			startfract(f);
			mlx_hook(f->mlx.win, 4,  mouseevent, f);
			mlx_hook(f->mlx.win, 2,  keyevent, f);
}

void	startfract(t_fractol *f);
{

	
void	draw(t_fractol *f, int x, int y, int color)
{
	int	pixel;

	pixel = ((y * f->image.line_bytes) + (x * 4));
	if (f->image.endian == 1)
	{
		f->image.data[pixel + 0] = (color >> 24);
		f->image.data[pixel + 1] = (color >> 16) & 0xFF;
		f->image.data[pixel + 2] = (color >> 8) & 0xFF;
		f->image.data[pixel + 3] = (color) & 0xFF;
		}
	else if (f->image.endian == 0)
	{
		f->image.data[pixel + 3] = (color >> 24);
		f->image.data[pixel + 2] = (color >> 16) & 0xFF;
		f->image.data[pixel + 1] = (color >> 8) & 0xFF;
		f->image.data[pixel + 0] = (color) & 0xFF;
	}
}

void	setman(t_fractol *f)
{

