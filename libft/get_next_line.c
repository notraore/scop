/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:13:24 by notraore          #+#    #+#             */
/*   Updated: 2017/09/21 12:32:38 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_stock		*ft_create_fd(int fd)
{
	t_stock		*file;

	if (!(file = (t_stock *)malloc(sizeof(t_stock))))
		return (NULL);
	if (file)
	{
		file->fd = fd;
		file->str = ft_strnew(0);
		file->next = NULL;
	}
	return (file);
}

static void			ft_last_fd(t_stock **file, int fd)
{
	t_stock *tmp;

	tmp = *file;
	if (!tmp)
		*file = ft_create_fd(fd);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_fd(fd);
	}
}

static t_stock		*ft_same_fd(t_stock **file, int fd)
{
	t_stock *tmp;

	tmp = *file;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	ft_last_fd(file, fd);
	return (ft_same_fd(file, fd));
}

static int			ft_storage(char **stocker, char *target, char **line)
{
	t_stock		tool;

	tool.save = *stocker;
	if (target != NULL)
	{
		tool.rest = ft_strchr(target, '\n');
		*tool.rest = '\0';
		*line = ft_strjoin(tool.save, target);
		*stocker = ft_strdup(tool.rest + 1);
	}
	else
	{
		tool.rest = ft_strchr(*stocker, '\n');
		*tool.rest = '\0';
		*line = ft_strdup(*stocker);
		*stocker = ft_strdup(tool.rest + 1);
	}
	free(tool.save);
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static t_stock	*tool;
	t_stock			*ds;

	ds = ft_same_fd(&tool, fd);
	if (BUFF_SIZE <= 0 || (!line) || (ds->fd < 0))
		return (-1);
	ds->str = (!ds->str) ? ft_strnew(0) : ds->str;
	if (ft_strchr(ds->str, '\n') != 0)
		return (ft_storage(&ds->str, NULL, line));
	while ((ds->ret = read((ds->fd), ds->buff, BUFF_SIZE)) > 0)
	{
		ds->buff[ds->ret] = '\0';
		if (ft_strchr(ds->buff, '\n') != 0)
			return (ft_storage(&ds->str, ds->buff, line));
		ds->tmp = ds->str;
		ds->str = ft_strjoin(ds->str, ds->buff);
		free(ds->tmp);
	}
	if (ds->str != 0 && ft_strlen(ds->str) != 0 && (*line = ft_strdup(ds->str)))
	{
		free(ds->str);
		ds->str = NULL;
		return (1);
	}
	return (ds->ret);
}
