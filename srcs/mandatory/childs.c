/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:22:06 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/17 18:58:53 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_parent(t_args *args)
{
	int	i;

	i = -1;
	close(args->in);
	close(args->out);
	while (args->cmd_p[++i])
		free(args->cmd_p[i]);
	free(args->cmd_p);
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

void	first_child(t_args *args, char **av, char **envp)
{
	args->cmd_args = ft_split(av[2], ' ');
	args->cmd = ft_get_cmd(args->cmd_p, args->cmd_args[0]);
	if (!args->cmd)
	{
		write(2, args->cmd_args[0], ft_strlen(args->cmd_args[0]));
		write(2, ": Command not found.\n", 21);
		free_child(args);
		free_parent(args);
		exit(EXIT_FAILURE);
	}
	dup2(args->pipe[1], STDOUT_FILENO);
	close(args->pipe[0]);
	dup2(args->in, STDIN_FILENO);
	execve(args->cmd, args->cmd_args, envp);
}

void	second_child(t_args *args, char **av, char **envp)
{
	args->cmd_args = ft_split(av[3], ' ');
	args->cmd = ft_get_cmd(args->cmd_p, args->cmd_args[0]);
	if (!args->cmd)
	{
		write(2, args->cmd_args[0], ft_strlen(args->cmd_args[0]));
		write(2, ": Command not found.\n", 21);
		free_child(args);
		free_parent(args);
		exit(EXIT_FAILURE);
	}
	dup2(args->pipe[0], STDIN_FILENO);
	close(args->pipe[1]);
	dup2(args->out, STDOUT_FILENO);
	execve(args->cmd, args->cmd_args, envp);
}
