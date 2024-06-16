/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:31:38 by ael-moua          #+#    #+#             */
/*   Updated: 2024/06/15 11:29:49 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

static char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*p;
	int				index;
	unsigned int	size;

	if (!s)
		return (NULL);
	size = (unsigned int) ft_strlen(s);
	index = 0;
	if (len > size - start)
		len = size - start;
	if (start > size)
		len = 0;
	p = (char *) malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	if (size >= start)
	{
		while (s[start] != '\0' && len)
		{
			p[index++] = s[start++];
			len--;
		}
	}
	p[index] = '\0';
	return (p);
}

static char	*ft_newline(char **line)
{
	char	*res;
	int		index;
	char	*tmp;

	index = 0;
	tmp = NULL;
	if (!*line)
		return (free(*line), *line = NULL, NULL);
	while ((*line)[index] != '\n' && (*line)[index] != '\0')
		index++;
	if (ft_checknl(*line) == 0 && (*line)[index + 1] != '\0')
	{
		res = ft_substr(*line, 0, index + 1);
		if (!res)
			return (free(*line), *line = NULL, NULL);
		tmp = ft_substr(*line, index + 1, ft_strlen(*line) - index);
		if (!tmp)
			return (free(*line), free(res), res = NULL, *line = NULL, NULL);
	}
	else
		res = ft_strdup(*line);
	if (!res)
		return (free(*line), *line = NULL, NULL);
	return (free(*line), *line = tmp, res);
}

static int	ft_protection(char *line, int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0
		|| BUFFER_SIZE > 2147479552)
	{
		if (line)
			free(line);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;
	int			size;
	char		*tmp;

	if (ft_protection(line, fd))
		return (line = NULL, NULL);
	while (ft_checknl(line))
	{
		buf = (char *) malloc((size_t)BUFFER_SIZE + 1);
		if (!buf)
			return (free(line), line = NULL, NULL);
		size = read(fd, buf, BUFFER_SIZE);
		if (size == 0)
			return (free(buf), buf = NULL, ft_newline(&line));
		buf[size] = '\0';
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
		free(buf);
		tmp = NULL;
		buf = NULL;
	}
	return (ft_newline(&line));
}
