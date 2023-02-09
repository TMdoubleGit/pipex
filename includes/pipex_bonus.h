/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:06:54 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/19 08:59:21 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	int		ac;
	int		here_doc;
	int		*pipe;
	int		pipe_nbr;
	int		cmd_nbr;
	int		cmd_id;
	char	**cmd_args;
	char	**cmd_p;
	char	*cmd;
	pid_t	pid;
}			t_args;

//CHILDS.C
void	free_parent(t_args *args);
void	free_child(t_args *args);
void	ft_dup(int fd1, int fd2, t_args *args);
void	child(t_args *args, char **av, char **envp);
//UTILS.C
void	create_pipes(t_args *args);
void	close_pipes(t_args *args);
void	ft_error(char *err);
//INITIALIZATION.C
void	get_infile(char **av, t_args *args);
void	get_outfile(char **av, t_args *args);
void	ft_get_env(char **envp, t_args *args);
char	*ft_get_cmd(char **cmd_p, char *cmd);
//HERE_DOC.C
int		min_args(char *infile, t_args *args);
void	open_here_doc(t_args *args);
void	here_doc(char *limiter, t_args *args);

#endif
