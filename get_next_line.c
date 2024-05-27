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

static void	free_and_null(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*set_line(char **stash)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	while ((*stash)[i] != '\n' && (*stash)[i] != '\0')
		i++;
	if ((*stash)[i] == '\0')
	{
		line = ft_strdup(*stash);
		free_and_null(stash);
		return (line);
	}
	line = ft_substr(*stash, 0, i + 1);
	temp = ft_strdup(*stash + i + 1);
	free_and_null(stash);
	*stash = temp;
	return (line);
}

/*Takes the line created in fill_line, checks for a new line or a NULL.
If NULL is found stash should be empty as it is in the end of the file.
If new line found it is set to NULL. If null is not found, a substring
of the line starting from after the new line is made and returned to be 
set as stash*/

static char	*fill_stash(int fd, char *stash)
{
	ssize_t	b_read;
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	b_read = 1;
	while (b_read != 0 && !ft_strchr(stash, '\n'))
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(stash);
			return (NULL);
		}
		buf[b_read] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}
/*reads through fd while buf does not contain a new line or NULL. It joins stash
and buf together and continues until buf does contain a new line or NULL. It then
sends the stash to the set_line funcion.*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = set_line(&stash);
	return (line);
}
/*Checks first that fd and BUFFER_SIZE are valid. It then makes a buffer (buf)
of size BUFFER_SIZE + 1.*/
