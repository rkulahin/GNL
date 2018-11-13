/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkulahin <rkulahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:44:23 by rkulahin          #+#    #+#             */
/*   Updated: 2018/11/12 09:52:28 by rkulahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

t_list	*find_list(t_list *start, const int fd)
{
	t_list *tmp;

	tmp = start;
	if (start)
	{
		if (tmp->content_size == fd)
		{
			return (tmp);
		}
		while (tmp->next)
		{
			if (tmp->content_size == fd)
			{
				return (tmp);
			}
			tmp = tmp->next;
		}
	}
	tmp->next = malloc(sizeof(t_list));
	tmp = tmp->next;
	tmp->content_size = fd;
	return (tmp);
}

char	*if_n_str(t_list *list, const int fd)
{
	char	buf[BUFF_SIZE];
	char	*tmp;
	int		size;

	size = read(fd, buf, BUFF_SIZE);
	tmp = ft_strjoin(list->content, buf);
	free(list->content);
	if (size == 0)
		return (NULL);
	list->content = tmp;
	return (if_find(list, fd));
}

char	*if_find(t_list *list, const int fd)
{
	char	*str;
	char	*ret;
	int		lc;
	int		len;

	len = 0;
	if (!(list->content))
	{
		list->content = ft_strnew(BUFF_SIZE);
	}
	if (ft_strchr(list->content, '\n'))
	{
		str = ft_strcpy(str, list->content);
		len = ft_lenword(str, '\n');
		lc = ft_lenword(list->content, '\0');
		lc = lc - len;
		list->content = ft_memmove(list->content,(ft_strchr(list->content, '\n') + 1), lc);
		ret = malloc(len);
		return (ft_strncpy(ret, str, len));
	}
	return (if_n_str(list, fd));
}

int		get_next_line(const int fd, char **line)
{
	static	t_list	*node;
	t_list			*tmp;

	*line = NULL;
	if (!node)
	{
		node = (t_list *)malloc(sizeof(t_list));
		node->content_size = fd;
		node->content = NULL;
	}
	tmp = find_list(node, fd);
	while (*line == NULL || (ft_strchr(*line, '\n')) == NULL)
	{
		*line = if_find(tmp, fd);
	}
	if (*line == NULL)
		return (0);

	return (1);
}
