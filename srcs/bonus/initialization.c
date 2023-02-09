/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:59:38 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/19 08:56:17 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	get_infile(char **av, t_args *args)
{
	if (!ft_strncmp("here_doc", av[1], 9))
		here_doc(av[2], args);
	else
	{
		args->in = open(av[1], O_RDONLY);
		if (args->in < 0)
			ft_error("An error has occurred while opening Infile.\n");
	}
}

void	get_outfile(char **av, t_args *args)
{
	if (!ft_strncmp("here_doc", av[1], 9))
		args->out = open(av[args->ac - 1], O_APPEND | O_CREAT
				| O_WRONLY, 0000644);
	else
		args->out = open(av[args->ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (args->out < 0)
		ft_error("An error has occurred while opening Outfile.\n");
}

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
