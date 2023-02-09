/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:51:40 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/19 08:59:10 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	min_args(char *infile, t_args *args)
{
	if (!ft_strncmp("here_doc", infile, 8))
	{
		args->here_doc = 1;
		return (6);
	}
	else
	{
		args->here_doc = 0;
		return (5);
	}
}

void	open_here_doc(t_args *args)
{
	args->in = open("here_doc", O_RDONLY);
	if (args->in < 0)
	{
		unlink("here_doc");
		ft_error("An error has occurred while opening here_doc.\n");
	}
}

void	here_doc(char *limiter, t_args *args)
{
	int		fd;
	char	*buf;

	fd = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (fd < 0)
		ft_error("An error has occurred while opening here_doc.\n");
	while (1)
	{
		write(1, "here_doc> ", 10);
		buf = get_next_line(0, 0);
		if (!buf)
			exit(EXIT_FAILURE);
		if (!ft_strncmp(limiter, buf, ft_strlen(limiter)))
		{
			free(buf);
			break ;
		}
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
		free(buf);
	}
	get_next_line(1, 1);
	close(fd);
	open_here_doc(args);
}
