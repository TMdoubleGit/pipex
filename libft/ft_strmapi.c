/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:00:02 by tmichel-          #+#    #+#             */
/*   Updated: 2022/11/20 15:13:57 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

/*char	f(unsigned int n, char c)
{
	(void)n;
	c = c + 1;
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	while (*(s + i))
	{
		*(res + i) = (*f)(i, *(s + i));
		i++;
	}
	*(res + i) = '\0';
	return (res);
}

/*int	main()
{
	char const	*s = "Salut";
	unsigned int	n = 1;
	char	c = 'a';
	printf("%c\n", f(n, c));
	printf("%s\n", ft_strmapi(s, &f));
	return (0);
}*/