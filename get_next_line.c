/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:23:24 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/29 15:42:48 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*output;
	size_t		i;

	output = NULL;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i + 1] && buffer[i] == '\n')
	{
		strreplace(&output, strnjoin(output, buffer + i + 1, BUFFER_SIZE));
		i = 0;
		while (i < BUFFER_SIZE + 1)
			buffer[i++] = '\0';
	}
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		strreplace(&output, strnjoin(output, buffer, i + 1));
		if (buffer[i] == '\n')
			break ;
	}
	return (output);
}
