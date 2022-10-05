/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:55:50 by jtanner           #+#    #+#             */
/*   Updated: 2022/09/01 16:44:38 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../mlx/mlx.h"
#include "../includes/fractol.h"
#include "../includes/keys.h"

int	rgbtoint(double r, double g, double b)
{
	int	color;

	color = 0;
	color |= (int)(b * 255);
	color |= (int)(g * 255) << 8;
	color |= (int)(r * 255) << 16;
	return (color);
}

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

int	fcheck(char *word)
{
	if (word[0] == 'j' || word[0] == 'J')
		return (2);
	if (word[0] == 'm' || word[0] == 'M')
		return (1);
	if (word[0] == 'B' || word[0] == 'b')
		return (3);
	else
		return (0);
}

int	instruction(void *param)
{
	int	i;

	i = 0;
	write(STDOUT_FILENO, "\e[1;1H\e[2J", 12);
	while (i++ < 7)
		ft_putstr("");
	param = NULL;
	ft_putstr("                               Instructions:");
	ft_putstr("                    To use type: ./fractol [Fractol Name]");
	ft_putstr("                    Current models: [Mandelbrot] [Julia] [Bar]");
	ft_putstr("");
	ft_putstr("                                Controls:");
	ft_putstr("                    Move: WSAD/Arrows");
	ft_putstr("                    Zoom in/out: Z/X/Mouse Wheel");
	ft_putstr("                    Change Colors: Click shit on mouse, also C");
	ft_putstr("                    Change Julia: J/K");
	while (i++ < 16)
		ft_putstr("");
	exit(0);
}
