/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:55:09 by mmatamou          #+#    #+#             */
/*   Updated: 2017/01/27 20:51:42 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int		fillstr(char **str, char *buf, int ret)
{
	char *tmp;

	buf[ret] = '\0';
	if (*str == NULL)
		*str = ft_strdup(buf);
	else
	{
		tmp = ft_strdup(*str);
		free(*str);
		*str = (char*)malloc(sizeof(char) * (ft_strlen(tmp) + ret + 1));
		if (*str == NULL)
			return (-1);
		ft_strcpy(*str, tmp);
		ft_strcat(*str, buf);
		free(tmp);
	}
	return (0);
}

static int		last(char **str, char **line, char *nl)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*str)[i] != '\n')
		i = i + 1;
	*line = (char*)malloc(sizeof(char) * (i + 1));
	(*line)[0] = '\0';
	ft_strncpy(*line, *str, i);
	(*line)[i] = '\0';
	if (nl[1] == '\0')
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	tmp = ft_strdup(nl + 1);
	free(*str);
	*str = ft_strdup(tmp);
	free(tmp);
	return (1);
}

static	t_fds	*fdsinit(t_fds *blc, int fd, t_fds *previous)
{
	blc->cfd = fd;
	blc->next = NULL;
	blc->str = NULL;
	blc->prev = previous;
	return (blc);
}

static	t_fds	*mfds(t_fds *orig, int fd)
{
	t_fds *previous;

	previous = NULL;
	if (orig != NULL)
	{
		while ((orig)->prev != NULL)
			orig = (orig)->prev;
		while (orig->next != NULL)
		{
			if ((orig)->cfd == fd)
				return (orig);
			orig = (orig)->next;
		}
		if ((orig)->cfd == fd)
			return (orig);
		orig->next = (t_fds*)malloc(sizeof(t_fds));
		previous = orig;
		orig = orig->next;
	}
	else
		orig = (t_fds*)malloc(sizeof(t_fds));
	orig = fdsinit(orig, fd, previous);
	return (orig);
}

int				get_next_line(const int fd, char **line)
{
	static t_fds	*curr = NULL;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*nl;

	ret = read(fd, buf, BUFF_SIZE);
	if ((fd < 0) || (ret == -1) || (line == NULL))
		return (-1);
	if ((curr = mfds(curr, fd)) == NULL)
		return (-1);
	if ((curr->str == NULL) && (ret == 0))
	{
		*line = NULL;
		return (0);
	}
	if (fillstr(&(curr->str), buf, ret) == -1)
		return (-1);
	if (((nl = ft_strchr(curr->str, '\n')) == NULL) && (ret == BUFF_SIZE))
		return (get_next_line(fd, line));
	if (nl != NULL)
		return (last(&(curr->str), line, nl));
	*line = ft_strdup(curr->str);
	free(curr->str);
	curr->str = NULL;
	return (1);
}
