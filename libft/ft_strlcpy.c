/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:25:20 by tmichel-          #+#    #+#             */
/*   Updated: 2022/11/17 13:42:04 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (src[j])
		j++;
	if (!size)
		return (j);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}
/*
int	main(void)
{
	size_t size;

	char dest[] = "Salut c'est cool";
	char src[] = "Coucou";
	size = 4;

	printf("%ld\n", ft_strlcpy(dest, src, size));
	printf("%ld\n", strlcpy(dest, src, size));
}*/
