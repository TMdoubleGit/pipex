/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:42:43 by tmichel-          #+#    #+#             */
/*   Updated: 2022/11/17 15:21:47 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!big)
		return (NULL);
	if (*(little) == 0)
		return ((char *)big);
	i = ft_strlen((char *)little);
	if (i > len)
		return (NULL);
	j = 0;
	k = 0;
	while (*(big + j) && j < len)
	{
		while ((j + k) < len && *(big + j + k) == *(little + k))
		{
			k++;
			if (!*(little + k))
				return (&*(char *)(big + j));
		}
		j++;
	}
	return (NULL);
}
/*
int	main()
{
	const char	*big;
	const char	*little;
	size_t	len;

	big = "oh no not the empty string !";
	little = "";
	len = ft_strlen((char *)big);
	printf("%s\n", ft_strnstr(big, little, len));
	//printf("%p\n", strnstr(big, little, len));
	return 0;
}*/
