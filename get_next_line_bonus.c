/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:23:24 by mnouchet          #+#    #+#             */
/*   Updated: 2022/12/14 14:54:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
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
	static char		buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char			*output;
	size_t			i;

	if (!fd || fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 0)
		return (NULL);
	output = NULL;
	i = 0;
	while (buffer[fd][i] && buffer[fd][i] != '\n')
		i++;
	if (buffer[fd][i] == '\n' && buffer[fd][i + 1])
		strreplace(&output, strnjoin(output, buffer[fd] + i + 1, BUFFER_SIZE));
	clear_buffer(buffer[fd]);
	while (read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		i = 0;
		while (buffer[fd][i] && buffer[fd][i] != '\n')
			i++;
		strreplace(&output, strnjoin(output, buffer[fd], i + 1));
		if (buffer[fd][i] == '\n')
			break ;
		clear_buffer(buffer[fd]);
	}
	return (output);
}
