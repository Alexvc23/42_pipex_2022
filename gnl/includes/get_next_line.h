/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:55:06 by jvalenci          #+#    #+#             */
/*   Updated: 2021/12/13 11:59:03 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<sys/select.h>
# include<sys/types.h>
# include<sys/stat.h>
# include<fcntl.h>
# include<unistd.h>
# include<stdlib.h>
# define GNL_ERROR 0
# define GNL_NEW_LINE 1
# define GNL_NO_NEW_LINE 2
# define GNL_EOF 3

/* STRUCTURES */

typedef struct s_buffer
{
	int		start;
	int		next_l;
	int		end;
	char	*data;
}			t_buffer;

/* FONCTION PROTOYPES */

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);

#endif
