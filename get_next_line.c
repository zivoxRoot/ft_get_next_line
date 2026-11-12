/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:09:13 by tdefeche          #+#    #+#             */
/*   Updated: 2026/11/12 11:47:19 by tdefeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>


size_t  ft_strlen(const char *s)
{
	size_t  i;

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

char    *ft_strdup(const char *s)
{
	size_t  size;
	char    *res;
	size_t  i;

	size = ft_strlen(s) + 1;
	res = (char *)malloc(size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
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
		return (ft_strdup(""));
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

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*buffer;
	char		*tmp;

	next_line = malloc(BUFFER_SIZE * sizeof(char));
	if (!next_line)
		return (NULL);
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	while (1 == 1)
	{
		read(fd, buffer, BUFFER_SIZE);
		// Look for \n
		int	i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				tmp = ft_strjoin(next_line, ft_substr(buffer, 0, i));
				next_line = ft_substr(buffer, i, ft_strlen(buffer) - i);
				return (tmp);
			}
		}
	}
}

// TODO: delete this test function
#include <fcntl.h>
int	main(void)
{
	const char	*file;

	file = "test.txt";
	// Open the file descriptor
	int	fd = open(file, O_RDONLY);
	if (!fd)
	{
		printf("Error opening file: %s\n", file);
		return (1);
	}

	// Call our function
	printf("-- %s\n", get_next_line(fd));

	// Close file descriptor
	close(fd);
}
