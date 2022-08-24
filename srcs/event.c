/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:28:47 by jtanner           #+#    #+#             */
/*   Updated: 2022/08/22 19:22:41 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	zoomin(int	mousecontroll, t_fractol *f)
{


int	mouseevent(int mouse, int x, int y, t_fractol *f)
{
	if (mouse == SCROLL_UP)
		zoom(f);
	if (mouse == SCROLL_DOWN)
		zoomout(f);

