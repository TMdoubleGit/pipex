/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:30:56 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/19 15:53:29 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	create_pipes(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->cmd_nbr - 1)
	{
		if (pipe(args->pipe + 2 * i) < 0)
		{
			free_parent(args);
			ft_error("An error has occurred while creating pipe.\n");
		}
	}
}

void	close_pipes(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->pipe_nbr)
		close(args->pipe[i]);
}

void	ft_error(char *err)
{
	write(2, err, ft_strlen(err));
	exit(EXIT_FAILURE);
}
