/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:43:39 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/17 17:07:12 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_args	args;

	if (ac != 5)
		ft_error("Invalid number of arguments.\n");
	args.in = open(av[1], O_RDONLY);
	if (args.in < 0)
		ft_error("An error has occurred while opening Infile.\n");
	args.out = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (args.out < 0)
		ft_error("An error has occured while opening Outfile.\n");
	if (pipe(args.pipe) < 0)
		ft_error("An error has occurred while creating pipe.\n");
	ft_get_env(envp, &args);
	args.pid1 = fork();
	if (!args.pid1)
		first_child(&args, av, envp);
	args.pid2 = fork();
	if (!args.pid2)
		second_child(&args, av, envp);
	close_pipes(&args);
	waitpid(args.pid1, NULL, 0);
	waitpid(args.pid2, NULL, 0);
	free_parent(&args);
	return (0);
}
