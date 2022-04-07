/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:05:23 by jvalenci          #+#    #+#             */
/*   Updated: 2022/04/07 13:56:05 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

char	*ft_find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
	{
		envp++;
		if (!*envp)
			return (NULL);
	}
	return (*envp + 5);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_vars	pipex;

	if (argc < ft_check_arg(argc, argv, &pipex))
		ft_msg_error("Wrong number of arguments\n");
	ft_get_infile(&pipex, argv);
	ft_get_outfile(argv[argc -1], &pipex);
	pipex.n_cmds = ((argc - 3) - pipex.here_doc);
	pipex.n_pipes = ((pipex.n_cmds - 1) * 2);
	pipex.end = malloc(pipex.n_pipes * sizeof(int));
	if (!pipex.end)
		ft_close_files(&pipex);
	pipex.path = ft_find_path(envp);
	if (!pipex.path)
		ft_msg_error("Command not found\n");
	pipex.paths = ft_split(pipex.path, ':');
	if (!pipex.paths)
		ft_free_pipex(&pipex);
	ft_create_pipes(&pipex);
	pipex.iter = -1;
	while (++(pipex.iter) < pipex.n_cmds)
		ft_child_bonus(&pipex, argv);
	waitpid(-1, NULL, 0);
	ft_free_pipex(&pipex);
	return (0);
}
