/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 06:34:30 by jvalenci          #+#    #+#             */
/*   Updated: 2022/04/04 06:34:38 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

/*	Allow us to test the function, if success returns the fuction's path in 
    bash, else returns null */
char	*ft_get_command(char **paths, char *cmd)
{
	int		i;
	char	*new_cmd;
	char	*tmp;

	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin("/", cmd);
		new_cmd = ft_strjoin(paths[i], tmp);
		if (access(new_cmd, 0) == 0)
			return (new_cmd);
		free(tmp);
		free(new_cmd);
	}
	return (NULL);
}

void	ft_super_dup(int cero, int uno)
{
	dup2(cero, STDIN_FILENO);
	dup2(uno, STDOUT_FILENO);
}

void	ft_child_bonus(t_vars *p, char **argv)
{
	(void)argv;
	p->id = fork();
	if (!p->id)
	{
		if (p->iter == 0)
			ft_super_dup(p->infile, p->end[1]);
		else if (p->iter == (p->n_cmds - 1))
			ft_super_dup(p->end[(2 * p->iter) - 2], p->outfile);
		else
			ft_super_dup(p->end[(p->iter * 2) - 2], p->end[(2 * p->iter) + 1]);
		ft_close_pipes(p);
		p->cmd_args = ft_split(argv[p->iter + 2 + p->here_doc], ' ');
		p->cmd = ft_get_command(p->paths, p->cmd_args[0]);
		if (!p->cmd)
		{
			ft_free_pipex(p);
			perror("Error executing cmd: ");
			write(2, p->cmd, ft_strlen(p->cmd));
			perror("\n");
			exit(-1);
		}
		execv(p->cmd, p->cmd_args);
	}
}