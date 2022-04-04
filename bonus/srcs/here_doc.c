/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:39:11 by jvalenci          #+#    #+#             */
/*   Updated: 2022/04/04 14:50:44 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

/*  This functions allows us to simulate the here_doc behavior, we create a
	temporal file,  with a infite loop we read from stdin with the help of gnl
	up until we find the DELIMITER, then we close the file and we reopen it
	using its file descriptor as our infile to use it later on in with the
	pipe */
void	ft_here_doc(char *arg, t_vars *vars)
{
	int		file;
	char	*buf;

	buf = NULL;
	file = open(".tmp_here_doc", O_CREAT | O_RDWR | O_TRUNC, 00666);
	if (file < 0)
		ft_msg_error("Error creating here_doc\n");
	while (1)
	{
		write(1, "> ", 2);
		get_next_line(0, &buf);
		if (!ft_strncmp(buf, arg, ft_strlen(buf)))
			break ;
		write(file, buf, ft_strlen(buf) + 1);
		free(buf);
	}
	free(buf);
	close(file);
	vars->infile = open(".tmp_here_doc", O_RDONLY);
	if (vars->infile < 0)
	{
		unlink(".tmp_here_doc");
		ft_msg_error("Error opening .tmp_here_doc\n");
	}
}
