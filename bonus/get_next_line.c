/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:41:42 by aben-dri          #+#    #+#             */
/*   Updated: 2025/03/23 00:41:08 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
char	*ft_next_line(char *buff)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	if (!buff)
		return (NULL);
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] != '\n')
	{
		free(buff);
		return (NULL);
	}
	next = malloc(ft_strlen(buff) - i + 1);
	if (!next)
	{
		free(buff); // Free buff if malloc fails
		return (NULL);
	}
	i = i + 1;
	j = 0;
	while (buff[i])
		next[j++] = buff[i++];
	next[j] = '\0';
	free(buff);
	return (next);
}

char	*ft_getting_line(char *buff)
{
	int		i;
	char	*str;

	i = 0;
	if (!buff || !*buff)
		return (NULL);
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		str[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_reading_line(int fd, char *buff)
{
	char	*str;
	ssize_t	line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc((size_t)BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	line = 1;
	while (line > 0)
	{
		line = read(fd, str, BUFFER_SIZE);
		if (line == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		str[line] = '\0';
		buff = ft_strjoin(buff, str);
		if(!buff)
		{
			free(str);
			free(buff);
			return NULL;
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(str);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buff), NULL);
	buff = ft_reading_line(fd, buff);
	if (!buff)
		return (NULL);
	line = ft_getting_line(buff);
	if(!line)
		return NULL;
	buff = ft_next_line(buff);
	return (line);
}
