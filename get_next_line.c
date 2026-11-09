/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:09:13 by tdefeche          #+#    #+#             */
/*   Updated: 2026/11/09 12:23:27 by tdefeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	c;

	while (read(fd, c, 1) && c != '\n' && c != '\0')  // Read one byte at a time
	{
	}
}

// TODO: delete this test function
#include <fcntl.h>
int	main(void)
{
	// Open the file descriptor
	int	fd = open("test.txt", O_RDONLY);

	// Call our function
	printf("-- %s\n", get_next_line(fd));

	// Close file descriptor
	close(fd);
}
