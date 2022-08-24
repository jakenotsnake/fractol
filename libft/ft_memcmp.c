/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:51:02 by jtanner           #+#    #+#             */
/*   Updated: 2022/03/24 15:18:31 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s11;
	const unsigned char	*s22;

	i = 0;
	s22 = (const unsigned char *)s2;
	s11 = (const unsigned char *)s1;
	while (n > i)
	{
		if (s22[i] != s11[i])
		{
			return (s11[i] - s22[i]);
		}
		i++;
	}
	return (0);
}
