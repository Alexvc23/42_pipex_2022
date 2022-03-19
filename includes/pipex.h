/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:55:27 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/19 15:01:59 by jvalenci         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include<unistd.h>
# include<stdio.h>
# include<sys/types.h>
# include<sys/stat.h>
# include<fcntl.h>
# include<sys/wait.h>
# include "../libft/includes/libft.h"
# include "../gnl/includes/get_next_line.h"
# define ERR_CMD "The command doesn't exist"

// ─── STRUCS ────────────────────────────────────────────────────────────────

typedef struct s_var
{
	char	*path_line;
	char	**paths_muline;
	char	**cmd_args;
	char	**cmd1_args;
	char	**envp;
	int		fd;
	int		fd1;
	int		end[2];
}	t_var;

// ─── FUCTIONS ──────────────────────────────────────────────────────────────

void	ft_pipex_free(t_var *vars);
void	msg_error(char *err);
char	*find_path(char **envp);
int		ft_parsing(t_var *vars, char *argv[], char **envp);
void	ft_child_process(t_var *vars, char **envp);
void	ft_parent_process(t_var *vars, char **envp);
void	ft_pipex(t_var *vars, char *envp[]);

#endif
