/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:09:13 by tdefeche          #+#    #+#             */
/*   Updated: 2026/11/10 14:04:31 by tdefeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE=12

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*buffer;

	rem = malloc(BUFFER_SIZE * sizeof(char));
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	while (read(fd, buffer, BUFFER_SIZE - ft_strlen(res)) != 0)
		continue ;
	// Look for \n
	int	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			rem = ft_substr(buffer, i, ft_strlen(&buffer[i]);
			returns (ft_substr(buffer, 0, i));
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
