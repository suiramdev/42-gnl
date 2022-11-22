/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:23:24 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/22 05:56:32 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	size_t		i;
	char		*output;

	output = NULL;
	i = 0;
	while (i < BUFFER_SIZE && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		i++;
		strreplace(&output, strjoin(output, buffer + i));
		buffer[0] = '\0';
	}
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		i = 0;
		while (i < BUFFER_SIZE && buffer[i] != '\n')
			i++;
		strreplace(&output, strnjoin(output, buffer, i + 1));
		if (buffer[i] == '\n')
			break ;
	}
	if (buffer[i] != '\n') // problem is here for sure, i think so...
	{
		printf("\nddd\n");
		free(output);
		return (NULL);
	}
	return (output);
}
