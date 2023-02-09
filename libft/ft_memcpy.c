/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:47:44 by tmichel-          #+#    #+#             */
/*   Updated: 2022/11/15 18:22:03 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *) dest;
	s = (char *) src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main()
{
	char	dest[15] = "abcdef";
	char	src[15] = "ghijkl"; 
	size_t	n;

	n = 6;
	printf("%s\n", (char *) ft_memcpy(dest, src, n));
	printf("%s\n", (char *) memcpy(dest, src, n));
	return (0);
}*/
