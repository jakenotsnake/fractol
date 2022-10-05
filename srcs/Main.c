/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:31:07 by jtanner           #+#    #+#             */
/*   Updated: 2022/09/01 16:44:40 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/fractol.h"
#include "../includes/keys.h"

void	startfract(t_fractol *f)
{
	int	c;

	c = 0;
	draw_fractal(f, c);
}

void	draw(t_fractol *f, int x, int y, int color)
{
	int	pixel;

	if (f->image.pix_bits != 32)
		color = mlx_get_color_value(f->mlx.init, color);
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

void	setfract(t_fractol *f)
{
	f->color.red = 6;
	f->color.green = 8;
	f->color.blue = 16;
	f->mouse.x = (WIDTH / 2);
	f->mouse.y = (HEIGHT / 2);
	f->fract.min_r = -2.4492;
	f->fract.max_r = 1.8758;
	f->fract.min_i = -1.5705;
	f->fract.max_i = 1.4254;
	f->fract.kr = -0.07732;
	f->fract.ki = -0.6464;
	f->image.color = 0x0001dd;
	f->mlx.init = mlx_init();
	f->image.image = mlx_new_image(f->mlx.init, WIDTH, HEIGHT);
}

int	main(int argc, char **argv)
{
	t_fractol	*f;

	write(STDOUT_FILENO, "\e[1;1H\e[2J", 12);
	if (argc == 2)
	{
		f = (t_fractol *)malloc(sizeof(t_fractol));
		setfract(f);
		if (!f)
			error();
		f->fract.fract = fcheck(argv[1]);
		if (f->fract.fract == 0)
			instruction(f->mlx.init);
		f->mlx.win = mlx_new_window(f->mlx.init, WIDTH, HEIGHT, argv[1]);
		f->image.image = mlx_new_image(f->mlx.init, WIDTH, HEIGHT);
		f->image.data = mlx_get_data_addr(f->image.image,
				&f->image.pix_bits, &f->image.line_bytes, &f->image.endian);
		startfract(f);
		mlx_hook(f->mlx.win, 4, 3, mouseevent, f);
		mlx_hook(f->mlx.win, 2, 3, keyevent, f);
		mlx_hook(f->mlx.win, 17, 3, instruction, f);
		mlx_loop(f->mlx.init);
	}
	f = NULL;
	instruction(f);
}
