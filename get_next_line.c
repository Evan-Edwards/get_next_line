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

char    *set_line(char *stash)
{
    int i;

    i = 0;
    while (stash[i])
    {
        if (stash[i] == '\n' || stash[i] == '\0')
            stash[i] = '\0';
            stash += i + 1;
            return (ft_substring(stash, 0, i + 1));
        i++;
    }
    return (ft_strdup(stash)); //shouldn't need it
}

/* Takes const char * stash, reads until \n or \0 is found. If found it sets a null
character at the end of the line. It returns a substring of the buffer to the
end of the line or to the end of the buffer */

char    *fill_line(int fd, char *left_c, char *buf)
{
    char    *new_line;
    
    while (strchr(buf, '\n') == NULL && strchr(buf, '\0') == NULL)
    {
        read(fd, buf, BUFFER_SIZE);
        stash = ft_strjoin(stash, buf); //can I join when it's empty?
    }
    stash = ft_strjoin(stash, buf);
    new_line = set_line(const char *stash);
    return (new_line);
}

char    *get_next_line(int fd)
{
    const char  *stash
    void        *buf;
    size_t      r;
    char        *new_line;

    buf = (void *)malloc (BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    if (fd < 0 || fd > 256)
        return (NULL);
    fd = open(fd, O_RDONLY); //open file

}