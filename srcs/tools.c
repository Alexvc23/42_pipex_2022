/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:17:58 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/16 15:35:54 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void ft_unfree(t_var *vars)
{
    ft_free(vars->cmd1_args);
    ft_free(vars->cmd_args);
    ft_free(vars->paths_muline);
}

void    ft_parsing(t_var *vars, char *argv[], char **envp)
{
    vars->path_line = find_path(envp);
    vars->paths_muline = ft_split(vars->path_line, ':');
    vars->cmd_args = ft_split(argv[2],' ');
    vars->cmd1_args = ft_split(argv[3],' ');
}