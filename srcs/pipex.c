/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:03:13 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/16 15:46:39 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void    ft_child_process(t_var *vars, char **envp)
{
    int     status;
    int     status1;
    int     i;
    char    *cmd;
    char    *brush;

    status = dup2(vars->fd, STDIN_FILENO);
    status1 = dup2(vars->end[1], STDOUT_FILENO);
    if (status < 0 || status1 < 0)
        msg_error("Error in dup2 child process\n");
    close(vars->end[0]);
    close(vars->fd);
    i = -1;
    while (vars->paths_muline[++i])
    {
        brush = ft_strjoin("/", vars->cmd_args[0]); 
        cmd = ft_strjoin(vars->paths_muline[i], brush);
        execve(cmd, vars->cmd_args, envp);
        free(brush);
        free(cmd);
    }
    ft_unfree(vars);
    msg_error("I didn't find any command in the child process\n");
}

void    ft_parent_process(t_var *vars, char **envp)
{
    int     status;
    int     i;
    char    *cmd;
    char    *brush;

    waitpid(-1, &status, 0);
    if (dup2(vars->fd1, STDOUT_FILENO) < 0 || dup2(vars->end[0], STDIN_FILENO) < 0) 
        msg_error("Error in dup2 parent process\n");
    close(vars->end[1]);
    close(vars->fd1);
    i = -1;
    while (vars->paths_muline[++i])
    {
        brush = ft_strjoin("/", vars->cmd1_args[0]); 
        cmd = ft_strjoin(vars->paths_muline[i], brush);
        execve(cmd, vars->cmd1_args, envp);
        // perror("Error executing execve in parent process\n");
        free(brush);
        free(cmd);
    }
    ft_unfree(vars);
    msg_error("I didn't find any command in the parent process\n");
}

void    ft_pipex(t_var *vars, char *envp[])
{
    pid_t parent;

    pipe(vars->end);
    parent = fork();
    if (parent < 0)
        msg_error("Error executing fork\n");
   if (!parent) 
        ft_child_process(vars, envp);
    else
        ft_parent_process(vars, envp);
}

int main(int argc, char *argv[], char *envp[])
{
    t_var vars;

    if (argc != 5)
        msg_error("You didn't provide correct number of arguments\n");
    vars.fd = open(argv[1], O_RDONLY);
    vars.fd1= open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 00777);
    
    if (vars.fd < 0 || vars.fd1 < 0)
        msg_error("There was a problem reading the files\n");

    ft_parsing(&vars, argv, envp);
    ft_pipex(&vars, envp);
    ft_unfree(&vars);
    return (0);
}