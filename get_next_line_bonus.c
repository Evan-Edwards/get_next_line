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
#include "get_next_line_bonus.h"
#include <stdio.h>

static void	free_stash(char **stash)
{
	if (*stash)
	{
		free(*stash);
		*stash = NULL;
	}
}

static char	*set_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (stash[i] == '\0')
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*next_stash(char *stash)
{
	int		i;
	char	*temp;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	if ((stash)[i] == '\0')
	{
		free_stash(&stash);
		return (NULL);
	}
	temp = ft_substr(stash, i, ft_strlen(stash) - i);
	if (!temp)
	{
		free_stash(&stash);
		return (NULL);
	}
	free_stash(&stash);
	return (temp);
}

/*Takes the line created in fill_line, checks for a new line or a NULL.
If NULL is found stash should be empty as it is in the end of the file.
If new line found it is set to NULL. If null is not found, a substring
of the line starting from after the new line is made and returned to be
set as stash*/

static char	*fill_stash(int fd, char **stash, char *buf)
{
	ssize_t	b_read;
	char	*temp;

	b_read = 1;
	if (!*stash)
		*stash = ft_strdup("");
	if (!*stash)
		return (NULL);
	while (b_read != 0 && !ft_strchr(*stash, '\n') && *stash)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read == -1)
		{
			free_stash(stash);
			return (NULL);
		}
		buf[b_read] = '\0';
		if (b_read == 0)
			break ;
		temp = *stash;
		*stash = ft_strjoin(*stash, buf);
		free(temp);
	}
	return (*stash);
}
/*reads through fd while buf does not contain a new line or NULL. It joins stash
and buf together and continues until buf does contain a new line or NULL. It then
sends the stash to the set_line funcion.*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[MAX_FD];
	char		*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || !buf)
	{
		free_stash(&stash[fd]);
		free_stash(&buf);
		return (NULL);
	}
	stash[fd] = fill_stash(fd, &stash[fd], buf);
	free (buf);
	if (!stash[fd])
		return (NULL);
	line = set_line(stash[fd]);
	if (!line)
	{
		free_stash(&stash[fd]);
		return (NULL);
	}
	stash[fd] = next_stash(stash[fd]);
	return (line);
}
/*Checks first that fd and BUFFER_SIZE are valid. It then fills the stash with 
fill_stash, gets the line to be output will set_line, and then set's the stash 
to be used the next time with next_stash.*/

/* int	main(void)
{
	int	fd;
	char *line1;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file\n");
		return (1);
	}
	line1 = get_next_line(fd);
	if (line1 != NULL)
	{
		printf("%s\n", line1);
		free(line1);
	}
	//while ((line = get_next_line(fd)) != NULL)

	close(fd);
	return (0);
} */
