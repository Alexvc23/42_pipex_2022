/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:55:27 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/18 16:24:45 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H
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
    
typedef struct  s_var 
{
    char    *path_line; //str with the path towars all the bash commands folders
    char    **paths_muline; // array with each commands folder by row
    char    **cmd_args; // commands passed as arguments to our program after calling ft_split over argv[2 || 4] 
    char    **cmd1_args; // commands passed as arguments to our program after calling ft_split over argv[2 || 4] 
    char    **envp; // all the environment variables separated by row after calling gnl over fd_envp
    int     fd;
    int     fd1;
    int     end[2];
}               t_var;

// ─── FUCTIONS ──────────────────────────────────────────────────────────────

void    ft_pipex_free(t_var *vars);
void	msg_error(char *err);
char	*find_path(char **envp);
void    ft_parsing(t_var *vars, char *argv[], char **envp);
void    ft_child_process(t_var *vars, char **envp);
void    ft_parent_process(t_var *vars, char **envp);
void    ft_pipex(t_var *vars, char *envp[]);

# endif
