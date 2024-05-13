/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:29:57 by eedwards          #+#    #+#             */
/*   Updated: 2024/05/07 13:30:02 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*set_line(char *stash)
{
	int		i;
	char	*stash_temp;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n' || stash[i] == '\0')
		{
			stash[i] = '\0';
			stash_temp = stash;
			stash += i + 1;
			return (ft_substr(stash_temp, 0, i + 1));
		}
		i++;
	}
	return (ft_strdup(stash));
}

/* Takes const char * stash,
	reads until \n or \0 is found. If found it sets a null
character at the end of the line. It returns a substring of the buffer to the
end of the line or to the end of the buffer */

static char	*fill_line(int fd, char *stash, char *buf)
{
	char	*new_line;
	char	*temp;
    ssize_t b_read;

    if (!stash)
	    stash = ft_strdup("");
	read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = '\0';
	while (ft_strchr(buf, '\n') == NULL)
	{
		temp = stash;
		stash = ft_strjoin(stash, buf);
		read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
	}
	new_line = set_line(stash);
	return (new_line);
}
/*reads through fd while buf does not contain a new line or NULL. It joins stash
and buf together and continues until buf does contain a new line or NULL. It then
sends the stash to the set_line funcion.*/

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*stash;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = fill_line(fd, stash, buf);
	free(buf);
    if (!line)
        return (NULL);
	return (line);
}
/*Checks first that fd and BUFFER_SIZE are valid. It then makes a buffer (buf)
of size BUFFER_SIZE + 1.*/