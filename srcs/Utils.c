/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:55:50 by jtanner           #+#    #+#             */
/*   Updated: 2022/08/22 14:33:14 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rgbtoint(double	r,	double	g,	double	b)
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
	int i;

	i = 0;
	// check if quotes includes a null terminator
	if (ft_strncmp(word, "Mandlebrot", 10))
		i = 1;
	else if (ft_strncmp(word, "Julia", 5))
		i = 2;
	return(i);
}

void	instruction()
{
	//
	//
	//
}
