/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:52:30 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/17 09:05:57 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			cut_line(char **s, char **line, int fd)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		if (!(*line = ft_strsub(s[fd], 0, len)))
			return (-1);
		if (!(tmp = ft_strdup(s[fd] + len + 1)))
			return (-1);
		free(s[fd]);
		s[fd] = tmp;
	}
	else
	{
		if (!(*line = ft_strdup(s[fd])))
			return (-1);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int			read_files(int fd, char **s, int ret)
{
	char		buff[BUFFY_SIZE + 1];
	char		*tmp;

	while ((ret = read(fd, &buff, BUFFY_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(s[fd], buff)))
			return (-1);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	static char	*s[MAX_FD];
	int			ret;
	int			len;

	ret = 1;
	len = 0;
	if (line == NULL || fd < 0 || fd > MAX_FD || BUFFY_SIZE < 1)
		return (-1);
	if (!s[fd])
		if (!(s[fd] = ft_strnew(1)))
			return (-1);
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
		return (cut_line(s, line, fd));
	else
	{
		ret = read_files(fd, s, ret);
		if (ret < 0)
			return (-1);
		if (ret == 0 && (s[fd][0] == '\0'))
			return (0);
	}
	return (cut_line(s, line, fd));
}
