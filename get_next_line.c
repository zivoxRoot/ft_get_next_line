/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:46:15 by tdefeche          #+#    #+#             */
/*   Updated: 2026/11/18 10:04:11 by tdefeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

///// START HELP
size_t  ft_strlen(const char *s)
{
	size_t  i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t                          i;
	unsigned char           *d;
	const unsigned char     *s;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (i < n)
	{
		*d = *s;
		d++;
		s++;
		i++;
	}
	return (dest);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
	int             size_s1;
	int             size_s2;
	char    *res;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	res = (char *)malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, size_s1);
	ft_memcpy(res + size_s1, s2, size_s2);
	res[size_s1 + size_s2] = '\0';
	return (res);
}

char    *ft_strchr(const char *s, int c)
{
	int     index;

	index = 0;
	if (!s)
		return (NULL);
	while (1 == 1)
	{
		if (s[index] == (char)c)
			return ((char *)&(s[index]));
		if (s[index] == '\0')
			break ;
		index++;
	}
	return (NULL);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	char    *res;
	size_t  i;
	size_t  s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	if (len > s_len - start)
		len = s_len - start;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_index_of(const char *s, int c)
{
	int     index;

	index = 0;
	if (!s)
		return (-1);
	while (1 == 1)
	{
		if (s[index] == (char)c)
			return (index);
		if (s[index] == '\0')
			break ;
		index++;
	}
	return (-1);
}
//// END HELP

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	int			byte_read;
	char		*tmp;
	char    	*line;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (!ft_strchr(stash, '\n') && byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		buffer[byte_read] = '\0';
		tmp = ft_strjoin((const char *)stash, (const char *)buffer);
		free(stash);
		stash = tmp;
	}
	free(buffer);
	if (!stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	byte_read = ft_index_of(stash, '\n');
	if (byte_read == -1)
		byte_read = ft_strlen(stash) - 1;
	line = ft_substr(stash, 0, byte_read + 1);
	tmp = ft_substr(stash, byte_read + 1, ft_strlen(stash));
	free(stash);
	stash = tmp;
	return (line);
}

int	main(int argc, char **argv)
{
	int 	fd;
	char	*str;

	if (argc == 1)
		fd = 0;
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			printf("Error opening file\n");
			return (1);
		}
	}

	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
		sleep(1);
	}

	close(fd);
	return (0);
}
