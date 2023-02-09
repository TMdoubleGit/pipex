/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:59:38 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/17 18:33:45 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_get_env(char **envp, t_args *args)
{
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
		{
			args->cmd_p = ft_split(*envp + 5, ':');
			if (!args->cmd_p)
			{
				free(args);
				exit(1);
			}
		}
		envp++;
	}
}

void	close_pipes(t_args *args)
{
	close(args->pipe[0]);
	close(args->pipe[1]);
}

char	*ft_get_cmd(char **cmd_p, char *cmd)
{
	char	*tmp;
	char	*full_cmd;

	while (*cmd_p)
	{
		tmp = ft_strjoin(*cmd_p, "/");
		full_cmd = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_cmd, 0) == 0)
			return (full_cmd);
		free(full_cmd);
		cmd_p++;
	}
	return (NULL);
}

void	ft_error(char *err)
{
	write(2, err, ft_strlen(err));
	exit(EXIT_FAILURE);
}
