/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:00:00 by jvalenci          #+#    #+#             */
/*   Updated: 2022/04/01 21:02:43 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

/* Determines whether the arg[1] is a normal file or here_doc */
void	ft_get_infile(t_vars *vars, char **argv)
{
	if (!strncmp(argv[1], "here_doc", 8))
		ft_here_doc(argv[2], vars);
	else
	{
		vars->infile = open(argv[1], O_RDONLY);
		if (vars->infile < 0)
			ft_msg_error("Error reading infile\n");
	}
}

/* Creats outfile depending on here_doc or normal infile */
void	ft_get_outfile(char *argv, t_vars *pipex)
{
	if (pipex->here_doc)
		pipex->outfile = open(argv, O_CREAT | O_RDWR | O_APPEND, 00644);
	else
		pipex->outfile = open(argv, O_CREAT | O_RDWR | O_TRUNC, 00644);
	if (pipex->outfile < 0)
		ft_msg_error("Error opening outfile\n");
}

void	ft_close_pipes(t_vars *p)
{
	int	i;

	i = -1;
	while (++i < p->n_pipes)
		close(p->end[i]);
}

void	ft_create_pipes(t_vars *p)
{
	int	i;

	i = 0;
	while (i < (p->n_cmds - 1))
	{
		if (pipe(p->end + (i * 2)) < 0)
			ft_free_pipex(p);
		i++;
	}
}
