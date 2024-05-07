/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:30:11 by eedwards          #+#    #+#             */
/*   Updated: 2024/05/07 13:30:15 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);

#endif