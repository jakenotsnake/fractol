/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:59:10 by jtanner           #+#    #+#             */
/*   Updated: 2022/08/22 16:06:29 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef	struct	t_image
{
	void	*image;
	char	*data;
	int		line_bytes;
	int		pix_bits;
	int		endian;
}

typedef	struct	t_mouse
{
	int		state;
	int		x;
	int		y;
}

typedef	struct	t_color
{
	int		red;
	int		green;
	int		blue;
}

typedef	struct	t_mlx
{
	void	init;
	void	win;
}

typedef	struct	t_fract
{
	int		fract;
	int		depth;
	int		iteration;
	double	witdth;
	double	height;
	double	scale;
	double	limit;
	double	x;
	double	y;
	double	kr;
	double	ki;
}

typedef	struct	t_fractol
{
	t_image	image;
	t_mouse	mouse;
	t_color	color;
	t_mlx	mlx;
	t_fract	fract;
}

