#include "get_next_line_bonus.h"

int	my_free_null(char **line, int res, char **remainder)
{
	if (*remainder)
	{
		free(*remainder);
		*remainder = NULL;
	}
	if ((res == 0 && !**line) || res < 0)
	{
		free(*line);
		*line = NULL;
	}
	return (res);
}

char	*check_remainder(char **remainder, char **line)
{
	char	*tmp;
	size_t	len;

	if (*remainder)
	{
		tmp = gnl_strchr(*remainder, '\n');
		len = gnl_strlen(*remainder);
		if (tmp)
			len = tmp - *remainder + 1;
		if (!gnl_strdup(*remainder, line, len))
			return (NULL);
		if (!tmp && *remainder)
			my_free_null(line, 1, remainder);
		else if (tmp++)
			if (!gnl_strdup(tmp, remainder, gnl_strlen(tmp)))
				return (NULL);
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * 1);
		if (!*line)
			return (NULL);
		**line = '\0';
	}
	return (*line);
}

int	get_line(int fd, char **line, char **remainder)
{
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			res;

	if (check_remainder(remainder, line) == NULL)
		return (-1);
	while (1)
	{
		if (*remainder)
			return (gnl_strlen(*line));
		res = read(fd, buf, BUFFER_SIZE);
		if (res <= 0)
			return (my_free_null(line, res, remainder));
		buf[res] = '\0';
		tmp = gnl_strchr(buf, '\n');
		if (tmp++)
		{
			if (!gnl_strdup(tmp, remainder, gnl_strlen(tmp)))
				return (-1);
			*tmp = '\0';
		}
		*line = gnl_strjoin(line, buf, gnl_strlen(*line), gnl_strlen(buf));
		if (!*line)
			return (-1);
	}
}

t_gnl	*new_list(int fd, t_gnl *tmp)
{
	t_gnl	*new;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->res = 0;
	new->remainder = NULL;
	new->prev = tmp;
	new->next = NULL;
	return (new);
}

char	*get_next_line(int fd)
{
	static t_gnl	*data;
	t_gnl			*tmp;
	char			*line;

	line = NULL;
	if (fd < 0)
		return (NULL);
	if (!data)
		data = new_list(fd, NULL);
	if (!data)
		return (NULL);
	tmp = data;
	while (tmp->fd != fd)
	{
		if (!tmp->next)
		{
			tmp->next = new_list(fd, tmp);
			if (!tmp->next)
				return (NULL);
		}
		tmp = tmp->next;
	}
	if (get_line(tmp->fd, &line, &tmp->remainder) <= 0)
		node_delete(&data, tmp);
	return (line);
}
