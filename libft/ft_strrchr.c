/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:38:07 by tmichel-          #+#    #+#             */
/*   Updated: 2022/11/18 18:15:26 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (!c)
		return ((char *)(s + i + 1));
	while (i >= 0)
	{
		if (*(char *)(s + i) == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

/*int	main()
{
	const char	*s;
	int	c;

	s = "Salut Thomas";
	c = 't' + 256;
	printf("%s\n", ft_strrchr(s, c));
	printf("%s\n", strrchr(s, c));
}*/
