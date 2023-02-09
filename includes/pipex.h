/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:06:54 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/17 18:33:53 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_args
{
	int		in;
	int		out;
	int		pipe[2];
	char	**cmd_args;
	char	**cmd_p;
	char	*cmd;
	pid_t	pid1;
	pid_t	pid2;
}			t_args;

//CHILDS.C
void	free_parent(t_args *args);
void	free_child(t_args *args);
void	first_child(t_args *args, char **av, char **envp);
void	second_child(t_args *args, char **av, char **envp);
//UTILS.C
void	ft_get_env(char **envp, t_args *args);
void	close_pipes(t_args *args);
char	*ft_get_cmd(char **cmd_p, char *cmd);
void	ft_error(char *err);

#endif
