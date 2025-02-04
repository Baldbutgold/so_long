/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadj <ael-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:30:35 by ael-hadj          #+#    #+#             */
/*   Updated: 2024/12/12 09:30:37 by ael-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*init_buf(int fd, char **line)
{
	char	*buf;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!*line)
		*line = ft_strdup("");
	if (!*line)
		return (free(buf), NULL);
	return (buf);
}

int	read_until_nl(int fd, char **line, char *buf)
{
	ssize_t	r_pos;
	char	*temp;

	r_pos = 1;
	while (ft_gnl_strchr(*line, '\n') == -1 && r_pos > 0)
	{
		r_pos = read(fd, buf, BUFFER_SIZE);
		if (r_pos == -1)
			return (-1);
		buf[r_pos] = '\0';
		temp = ft_strjoin(*line, buf);
		if (!temp)
			return (-1);
		free(*line);
		*line = temp;
	}
	return (r_pos);
}

char	*extract_line(char **line)
{
	char	*re_line;
	char	*temp;
	int		nl_pos;

	nl_pos = ft_gnl_strchr(*line, '\n');
	if (nl_pos >= 0)
	{
		re_line = ft_substr(*line, 0, nl_pos + 1);
		temp = ft_substr(*line, nl_pos + 1, ft_strlen(*line) - nl_pos - 1);
		free(*line);
		*line = temp;
	}
	else
	{
		re_line = ft_strdup(*line);
		free(*line);
		*line = NULL;
	}
	return (re_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;
	char		*re_line;
	ssize_t		r_pos;

	buf = init_buf(fd, &line);
	if (!buf)
		return (NULL);
	r_pos = read_until_nl(fd, &line, buf);
	if (r_pos == -1)
	{
		free(buf);
		free(line);
		line = NULL;
		return (NULL);
	}
	free(buf);
	if (r_pos == 0 && (!line || *line == '\0'))
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	re_line = extract_line(&line);
	return (re_line);
}
