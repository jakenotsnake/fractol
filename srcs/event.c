/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:28:47 by jtanner           #+#    #+#             */
/*   Updated: 2022/09/01 17:08:57 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../mlx/mlx.h"
#include "../includes/fractol.h"
#include "../includes/keys.h"

void	move(int key, t_fractol *f)
{
	double	dist;

	dist = 0.07;
	if (key == KEY_ANSI_A || key == KEY_LEFT)
	{
		f->fract.min_r -= (f->fract.max_r - f->fract.min_r) * dist;
		f->fract.max_r -= (f->fract.max_r - f->fract.min_r) * dist;
	}
	if (key == KEY_ANSI_D || key == KEY_RIGHT)
	{
		f->fract.min_r += (f->fract.max_r - f->fract.min_r) * dist;
		f->fract.max_r += (f->fract.max_r - f->fract.min_r) * dist;
	}
	if (key == KEY_ANSI_W || key == KEY_UP)
	{
		f->fract.min_i -= (f->fract.max_i - f->fract.min_i) * dist;
		f->fract.max_i -= (f->fract.max_i - f->fract.min_i) * dist;
	}
	if (key == KEY_ANSI_S || key == KEY_DOWN)
	{
		f->fract.min_i += (f->fract.max_i - f->fract.min_i) * dist;
		f->fract.max_i += (f->fract.max_i - f->fract.min_i) * dist;
	}
	if (key == KEY_ESCAPE)
		exit(0);
}

void	zoom(t_fractol *f, double z)
{
	f->fract.min_r = f->fract.max_r + z * (f->fract.min_r - f->fract.max_r);
	f->fract.max_r = f->fract.max_r + ((f->fract.min_r - f->fract.max_r)
			- z * (f->fract.min_r - f->fract.max_r)) / 2;
	f->fract.min_i = f->fract.max_i + z * (f->fract.min_i - f->fract.max_i);
	f->fract.max_i = f->fract.max_i + ((f->fract.min_i - f->fract.max_i)
			- z * (f->fract.min_i - f->fract.max_i)) / 2;
}

int	mouseevent(int mouse, int x, int y, t_fractol *f)
{
	x = 0;
	y = 0;
	if (mouse == SCROLL_UP)
		zoom(f, 0.8);
	if (mouse == SCROLL_DOWN)
		zoom(f, 1.25);
	if (mouse == RIGHT_CLK)
		f->image.color = (f->image.color / 2);
	if (mouse == LEFT_CLK)
		f->image.color = (f->image.color * 2);
	if (mouse == MIDDLE_CLK)
		f->image.color = f->image.color + 0x777777;
	startfract(f);
	return (1);
}

int	keyevent(int key, t_fractol *f)
{
	if (key == KEY_ANSI_W || key == KEY_ANSI_D || key == KEY_ANSI_S
		|| key == KEY_ANSI_A || key == KEY_LEFT || key == KEY_RIGHT
		|| key == KEY_UP || key == KEY_DOWN || key == KEY_ESCAPE)
		move(key, f);
	if (key == KEY_ANSI_Z)
		zoom(f, 0.95);
	if (key == KEY_ANSI_X)
		zoom(f, 1.15);
	if (key == KEY_ANSI_J)
	{
		f->fract.kr = (f->fract.kr * 1.018);
		f->fract.ki = (f->fract.ki * 1.05);
	}
	if (key == KEY_ANSI_K)
	{
		f->fract.kr = (f->fract.kr * 0.7);
		f->fract.ki = (f->fract.ki * 0.9);
	}
	if (key == KEY_ANSI_C)
	{
		f->image.color = 0xdd0000;
		f->image.end = 0xffffff;
	}
	startfract(f);
	return (1);
}
