/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:54:51 by jvalenci          #+#    #+#             */
/*   Updated: 2021/12/13 11:42:15 by jvalenci         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

void	ft_free(char **buffer)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
		buffer = NULL;
	}
}

void	ft_count_nl(t_buffer *t_buf)
{
	while (t_buf->next_l < t_buf->end)
	{
		t_buf->next_l++;
		if (t_buf->data[t_buf->next_l - 1] == '\n')
			break ;
	}
}

char	*ft_reassing_str(char **dest, t_buffer *t_buf)
{
	char	*new_str;
	int		dest_size;
	int		i;
	int		j;

	new_str = NULL;
	dest_size = 0;
	j = t_buf->start;
	i = 0;
	if (*dest)
		dest_size = ft_strlen(*dest);
	if (t_buf->end)
		new_str = malloc(dest_size + (t_buf->next_l - t_buf->start) + 1);
	if (!new_str)
		return (GNL_ERROR);
	while (i < dest_size)
	{
		new_str[i] = (*dest)[i];
		i++;
	}
	while (j < t_buf->next_l)
		new_str[i++] = t_buf->data[j++];
	new_str[i] = '\0';
	return (new_str);
}

int	ft_fetch_next_l(int fd, char **new_str, t_buffer *t_buf)
{
	char	*reassigned_str;

	if (t_buf->start >= t_buf->end)
	{
		t_buf->end = read(fd, t_buf->data, BUFFER_SIZE);
		t_buf->start = 0;
	}
	if (t_buf->end == -1)
		return (GNL_ERROR);
	t_buf->next_l = t_buf->start;
	ft_count_nl(t_buf);
	reassigned_str = ft_reassing_str(new_str, t_buf);
	t_buf->start = t_buf->next_l;
	if (!reassigned_str)
		return (GNL_ERROR);
	ft_free(new_str);
	*new_str = reassigned_str;
	if (t_buf->next_l < t_buf->end || t_buf->data[t_buf->next_l - 1] == '\n')
		return (GNL_NEW_LINE);
	if (t_buf->end < BUFFER_SIZE)
		return (GNL_EOF);
	return (GNL_NO_NEW_LINE);
}

char	*get_next_line(int fd)
{
	char			*new_str;
	int				result;
	static t_buffer	t_buf[FD_SETSIZE];

	new_str = 0;
	if (fd < 0 || fd > FD_SETSIZE)
		return (GNL_ERROR);
	if (t_buf[fd].data == 0)
	{
		t_buf[fd].data = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (!t_buf[fd].data)
			return (GNL_ERROR);
		t_buf[fd].start = BUFFER_SIZE;
	}
	result = GNL_NO_NEW_LINE;
	while (result == GNL_NO_NEW_LINE)
		result = ft_fetch_next_l(fd, &new_str, &t_buf[fd]);
	if (result == GNL_EOF || result == GNL_ERROR)
		ft_free(&t_buf[fd].data);
	return (new_str);
}
