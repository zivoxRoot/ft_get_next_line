/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefeche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:37:33 by tdefeche          #+#    #+#             */
/*   Updated: 2026/11/13 10:43:31 by tdefeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// TODO: add memcpy & memlen

void	*realloc(void *ptr, size_t size)
{
	void	*new;


	if (!ptr)
		return (malloc(size));
	if (ptr && size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new = malloc(size - ft_memlen(ptr));
	if (!new)
		return (NULL);
	return (ft_memcpy(ptr, new));
}
