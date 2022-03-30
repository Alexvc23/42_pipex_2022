/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bunus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:11:38 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/30 09:26:32 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
#define PIPEX_BONUS_H

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/*to perror*/
# include <stdio.h>

/* gnl */
#include"../gnl/includes/get_next_line.h"

/* libft */
#include"../libft/includes/get_next_line.h"

// ─── STRUCTURE ────────────────────────────────────────────────────────────
    
typedef struct	s_vars 
{
	char	*path;
	char	**paths;
	char	**cmd_args;
	int		infile;
	int		outfile;
	int		*pipes;
	int		here_doc;
	int		iter;
    int     n_cmds;     
    int     n_pipes;

}				t_vars;

// ─── FUNCTIONS ──────────────────────────────────────────────────────────────

int		ft_check_arg(int argc, char **argv, t_vars *pipex);
void	msg_error(char *err);
char	*ft_find_path(char **envp);
void    ft_here_doc(char *arg, t_vars *vars);
void	ft_get_infile(t_vars *vars, char **argv)
void	ft_get_oufile(char *argv, t_vars *pipex);
void    ft_free_error(t_vars *pipex);
void    ft_free_pipex(t_vars *pipex);
    
#endif