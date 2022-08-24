/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:45:27 by jtanner           #+#    #+#             */
/*   Updated: 2022/03/24 14:57:11 by jtanner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_isinset(char const *set, char c)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cp;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (ft_isinset(set, s1[count]))
		count++;
	if (count == (int)ft_strlen(s1))
	{
		cp = (char *)malloc(sizeof(char) * 1);
		cp[0] = 0;
		return (cp);
	}
	i = ft_strlen(s1) - 1;
	while (ft_isinset(set, s1[i]))
		i--;
	cp = ft_substr(s1, count, i - count + 1);
	return (cp);
}
