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

static char	*set_line(char *line)
{
	int		i;
	char	*stash_r;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	stash_r = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	if (stash_r && *stash_r == 0)
	{
		free(stash_r);
		stash_r = NULL;
	}
	line[i + 1] = '\0';
	return (stash_r);
}

/*Takes the line created in fill_line, checks for a new line or a NULL.
If NULL is found stash should be empty as it is in the end of the file.
If new line found it is set to NULL. If null is not found, a substring
of the line starting from after the new line is made and returned to be 
set as stash*/

static char	*fill_line(int fd, char *stash, char *buf)
{
	char	*temp;
	ssize_t	b_read;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(stash);
			return (NULL);
		}
		if (b_read == 0)
			break ;
		buf[b_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(stash, buf);
		free(temp);
		if (!stash)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}
/*reads through fd while buf does not contain a new line or NULL. It joins stash
and buf together and continues until buf does contain a new line or NULL. It then
sends the stash to the set_line funcion.*/

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0 < 0))
	{
		if(stash)
		{
			free(stash);
			stash = NULL;
		}
		return (NULL);
	}
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	line = fill_line(fd, stash, buf);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	stash = set_line(line);
	return (line);
}
/*Checks first that fd and BUFFER_SIZE are valid. It then makes a buffer (buf)
of size BUFFER_SIZE + 1.*/

/*
int	main()
{

}
*/