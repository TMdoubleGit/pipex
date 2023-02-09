/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:46:49 by tmichel-          #+#    #+#             */
/*   Updated: 2022/11/18 18:20:58 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (!c)
		return ((char *)(s + i + 1));
	while (*(char *)s != (char)c)
	{
		if (*(char *)s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

/*int	main()
{
	const char	*s;
	int	c;

	s = "tripouille";
	c = 't' + 256;
	printf("%p\n", ft_strchr(s, c));
	printf("%p\n", strchr(s, c));
	return (0);
}*/
