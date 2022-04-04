/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:10:48 by jvalenci          #+#    #+#             */
/*   Updated: 2022/04/01 18:35:31 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

/* If here_doc present in argv[1], argc must have at least 6 arguments
   else we must have at least 5 arguments */
int	ft_check_arg(int argc, char **argv, t_vars *pipex)
{
	if (argc >= 4)
	{
		if (argc && !ft_strncmp(argv[1], "here_doc", 9))
		{
			pipex->here_doc = 1;
			return (6);
		}
		else
		{
			pipex->here_doc = 0;
			return (5);
		}
	}
	ft_msg_error("Wrong number of arguments");
	return (0);
}

void	ft_close_files(t_vars *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	ft_msg_error("Environment Error\n");
}

void	ft_free_pipex(t_vars *pipex)
{
	ft_free((void **)pipex->paths);
	close(pipex->infile);
	close(pipex->outfile);
	ft_close_pipes(pipex);
	free(pipex->end);
	if (pipex->here_doc)
		unlink(".tmp_here_doc");
	exit(EXIT_SUCCESS);
}

void	ft_msg_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
