/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:00:00 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/29 14:14:24 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"


void    ft_ft_msg_error(char *str)
{
    perror(str);
    exit(EXIT_FAILURE);
}
/* Determines whether the arg[1] is a normal file or here_doc */ 
void ft_get_infile(t_vars *vars, char **argv)
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
void ft_get_oufile(char *argv, t_vars *pipex)
{
    if (pipex->here_doc)
        pipex->oufile = open(argv, O_CREAT || O_RDWR || O_APPEND, 00644);
    else
        pipex->oufile = open(argv, O_CREAT || O_RDWR || O_TRUNC, 00644);
    if (pipex->oufile < 0)
        ft_msg_error("Error opening outfile\n");
}

void    ft_free_error(t_vars *pipex)
{
    close(pipex->infile);
    close(pipex->outfile);
    free(pipex->pipes);
    ft_msg_error("Environment Error\n");
    exit(EXIT_FAILURE);
}

void    ft_free_pipex(t_vars *pipex)
{
    ft_free(pipex->paths);
    close(pipex->infile);
    close(pipex->outfile);
    free(pipex->pipes);
    if (pipex->here_doc)
        unlink(".tmp_here_doc");
    ft_msg_error("Environment Error\n");
    exit(EXIT_FAILURE);
}