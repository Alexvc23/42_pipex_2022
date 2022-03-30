/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:10:48 by jvalenci          #+#    #+#             */
/*   Updated: 2022/03/28 15:28:25 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

/* If here_doc present in argv[1], argc must have at least 6 arguments
   else we must have at least 5 arguments */
int ft_check_arg(int argc, char **argv, t_vars *pipex)
{
    if (argc && !ft_strncmp(argv[1], "here_doc", 9))
    {
        pipex->here_doc = 1;
        return (6);
    }
    else
    {
        pipex->here_doc = 0;
        return (5);
    }
    return (0);
}

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}