/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:49:11 by tmichel-          #+#    #+#             */
/*   Updated: 2022/11/18 17:57:52 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	ft_istrimm(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (*(char *)(set + i))
	{
		if (*(set + i) == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*trimmed;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	j = 0;
	k = 0;
	if (!set)
		return ((char *)s1);
	while (*(char *)(s1 + j) && ft_istrimm(set, *(char *)(s1 + j)) == 1)
		j++;
	while (*(char *)(s1 + j) && ft_istrimm(set, *(char *)(s1 + i - 1)) == 1)
		i--;
	trimmed = (char *)malloc(sizeof(char) * (i - j + 1));
	if (!trimmed)
		return (NULL);
	while (*(char *)(s1 + j) && j < i)
		*(char *)(trimmed + k++) = *(char *)(s1 + j++);
	*(char *)(trimmed + k) = '\0';
	return ((char *)(trimmed));
}

/*int	main()
{
	char const	*s1 = "||||||       |     kkke eeqqw//ekeeSalut Thomase  eee|";
	char const	*set = "| ";

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}*/