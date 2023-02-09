/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:22:06 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/19 08:54:36 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_parent(t_args *args)
{
	int	i;

	i = -1;
	close(args->in);
	close(args->out);
	if (args->here_doc)
		unlink("here_doc");
	while (args->cmd_p[++i])
		free(args->cmd_p[i]);
	free(args->cmd_p);
	free(args->pipe);
}

void	free_child(t_args *args)
{
	int	i;

	i = -1;
	while (args->cmd_args[++i])
		free(args->cmd_args[i]);
	free(args->cmd_args);
	free(args->cmd);
}

void	ft_dup(int fd1, int fd2, t_args *args)
{
	dup2(fd1, STDIN_FILENO);
	if (dup2(fd1, STDIN_FILENO) < 0)
	{
		free_parent(args);
		ft_error("An error has occurred while duplicating file descriptor.");
	}
	dup2(fd2, STDOUT_FILENO);
	if (dup2(fd2, STDOUT_FILENO) < 0)
	{
		free_parent(args);
		ft_error("An error has occurred while duplicating file descriptor.");
	}
}

void	child(t_args *args, char **av, char **envp)
{
	args->pid = fork();
	if (!args->pid)
	{
		args->cmd_args = ft_split(av[2 + args->here_doc + args->cmd_id], ' ');
		args->cmd = ft_get_cmd(args->cmd_p, args->cmd_args[0]);
		if (!args->cmd)
		{
			write(2, args->cmd_args[0], ft_strlen(args->cmd_args[0]));
			write(2, ": Command not found.\n", 21);
			free_child(args);
			free_parent(args);
			exit(EXIT_FAILURE);
		}
		if (args->cmd_id == 0)
			ft_dup(args->in, args->pipe[1], args);
		else if (args->cmd_id == args->cmd_nbr - 1)
			ft_dup(args->pipe[2 * (args->cmd_id - 1)], args->out, args);
		else
			ft_dup(args->pipe[2 * (args->cmd_id - 1)],
				args->pipe[2 * args->cmd_id + 1], args);
		close_pipes(args);
		execve(args->cmd, args->cmd_args, envp);
	}
}
