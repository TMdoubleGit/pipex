/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:04:36 by tmichel-          #+#    #+#             */
/*   Updated: 2022/11/15 18:22:09 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*t;

	i = 0;
	t = (char *) s;
	while (i < n)
	{
		t[i] = c;
		i++;
	}
	return (s);
}
/*
int	main()
{
	int	c;
	size_t	n;
	char	s[15] = "abcdefghij";

	c = 'a';
	n = 10;
	printf("%s\n", ft_memset(s, c, n));
	return 0;
}*/
