/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:43:39 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/19 08:47:27 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_args	args;

	if (ac < min_args(av[1], &args))
		ft_error("Invalid number of arguments.\n");
	args.ac = ac;
	get_infile(av, &args);
	get_outfile(av, &args);
	args.cmd_nbr = ac - 3 - args.here_doc;
	args.pipe_nbr = 2 * (args.cmd_nbr - 1);
	args.pipe = malloc(sizeof(int) * args.pipe_nbr);
	if (!args.pipe)
		ft_error("Malloc error has occurred.\n");
	ft_get_env(envp, &args);
	create_pipes(&args);
	args.cmd_id = -1;
	while (++args.cmd_id < args.cmd_nbr)
		child(&args, av, envp);
	close_pipes(&args);
	waitpid(-1, NULL, 0);
	free_parent(&args);
	return (0);
}
