/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:28:44 by jtanner           #+#    #+#             */
/*   Updated: 2022/03/25 12:52:26 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		c;
	int		h;
	char	*s3;

	h = 0;
	c = ft_strlen(s2);
	j = ft_strlen(s1);
	s3 = (char *)malloc(sizeof(char) *(j + c + 1));
	i = 0;
	while (i < j)
	{
	s3[i] = s1[i];
	i++;
	}
	while (s2[h] != '\0')
	{
	s3[i] = s2[h];
	i++;
	h++;
	}
	s3[i] = '\0';
	return (&*s3);
}
