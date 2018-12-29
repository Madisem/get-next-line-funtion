/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maseidua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 18:09:29 by maseidua          #+#    #+#             */
/*   Updated: 2018/11/16 16:49:19 by maseidua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	gnl_extra(char **line, char **buff)
{
	char	*arr1;
	int		k;

	if ((k = ft_strchr_i(*buff, '\n')) != -1)
	{
		*line = ft_strsub(*buff, 0, k);
		arr1 = ft_strsub(*buff, k + 1, ft_strlen(*buff) - k);
		free(*buff);
		*buff = arr1;
		return (1);
	}
	return (0);
}

static int	extra(char **line, char **buff)
{
	if (gnl_extra(line, buff) == 0)
	{
		*line = *buff;
		*buff = NULL;
		if (**line == 0)
			return (0);
	}
	return (1);
}

static	int	get_next_line_main(const int fd, char **line, char **buff)
{
	char	arr[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	ret = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE < 0)
		return (-1);
	while ((ret = read(fd, arr, BUFF_SIZE)) > 0)
	{
		arr[ret] = 0;
		if (*buff == NULL)
			*buff = ft_strnew(0);
		tmp = ft_strjoin(*buff, arr);
		free(*buff);
		*buff = tmp;
		if (gnl_extra(line, buff))
			return (1);
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && *buff)
		return (extra(line, buff));
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static	t_list	*new = NULL;
	t_list			*tmp;

	if (new == NULL)
	{
		new = ft_lstnew(NULL, 0);
		new->content_size = fd;
	}
	tmp = new;
	while (tmp && (fd != (int)(tmp->content_size)))
		tmp = tmp->next;
	if (!tmp)
	{
		ft_lstadd(&new, ft_lstnew(NULL, 0));
		new->content_size = fd;
		tmp = new;
	}
	return (get_next_line_main(fd, line, (char**)&(tmp->content)));
}
