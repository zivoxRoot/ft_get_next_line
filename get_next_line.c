/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:46:15 by tdefeche          #+#    #+#             */
/*   Updated: 2026/11/13 11:37:37 by tdefeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

///// HELP
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

//// END HELP

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	int			byte_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	buffer[byte_read] = '\0';
	stash = ft_strjoin((const char *)stash, (const char *)buffer);
	free(buffer);
	return (stash);
}

int	main(void)
{
	int fd;

	fd = open("test.txt", O_RDONLY);

	printf("%s\n", get_next_line(fd));

	close(fd);
	return (0);
}
