/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:23:24 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/29 18:59:13 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static void	clear_buffer(char buffer[BUFFER_SIZE + 1])
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*output;
	size_t		i;

	output = NULL;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n' && buffer[i + 1])
		strreplace(&output, strnjoin(output, buffer + i + 1, BUFFER_SIZE));
	clear_buffer(buffer);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		strreplace(&output, strnjoin(output, buffer, i + 1));
		if (buffer[i] == '\n')
			break ;
		clear_buffer(buffer);
	}
	return (output);
}
