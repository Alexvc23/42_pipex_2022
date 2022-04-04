/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:03:13 by jvalenci          #+#    #+#             */
/*   Updated: 2022/04/04 15:12:54 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* test every command before executing, if error we return null */
char	*ft_check_command(char **paths, char *cmd)
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

/* execution during the first process (the child process) containing
   cmd1 passed, defining fd1 as stdin for cmd1, and setting up our stdout
   that will stdin for cmd2 */
void	ft_child_process(t_var *vars, char **envp)
{
	char	*cmd;

	dup2(vars->fd, STDIN_FILENO);
	dup2(vars->end[1], STDOUT_FILENO);
	close(vars->fd);
	close(vars->end[0]);
	close(vars->end[1]);
	cmd = ft_check_command(vars->paths_muline, vars->cmd_args[0]);
	if (!cmd)
	{
		ft_pipex_free(vars);
		msg_error("The command doesn't exist in child process");
	}
	execve(cmd, vars->cmd_args, envp);
}

/* Second process execution containing cmd2, setting output file as cmd2'
   soutput and cmd1's output as cmd2's input*/
void	ft_parent_process(t_var *vars, char **envp)
{
	char	*cmd;
	int		status;

	waitpid(-1, &status, 0);
	dup2(vars->fd1, STDOUT_FILENO);
	dup2(vars->end[0], STDIN_FILENO);
	close(vars->end[1]);
	close(vars->end[0]);
	close(vars->fd1);
	cmd = ft_check_command(vars->paths_muline, vars->cmd1_args[0]);
	if (!cmd)
	{
		ft_pipex_free(vars);
		msg_error("The command doesn't exist in parent process");
	}
	execve(cmd, vars->cmd1_args, envp);
}

void	ft_pipex(t_var *vars, char *envp[])
{
	pid_t	parent;

	pipe(vars->end);
	parent = fork();
	if (parent < 0)
		msg_error("Error executing fork\n");
	if (!parent)
		ft_child_process(vars, envp);
	else
		ft_parent_process(vars, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_var	vars;

	if (argc != 5)
		msg_error("You didn't provide correct number of arguments\n");
	vars.fd = open(argv[1], O_RDONLY);
	vars.fd1 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 00777);
	if (vars.fd < 0 || vars.fd1 < 0)
		msg_error("There was a problem reading the files\n");
	if (!ft_parsing(&vars, argv, envp))
		msg_error("There was problem reading the arguments\n");
	ft_pipex(&vars, envp);
	ft_pipex_free(&vars);
	return (0);
}
