/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:23:28 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/28 23:49:53 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	const char	*s;

	if (!str)
		return (0);
	s = str;
	while (*s)
		s++;
	return (s - str);
}

void	strreplace(char **a, char *b)
{
	free(*a);
	*a = b;
}

char	*strjoin(char *s1, char *s2)
{
	char	*output;
	size_t	i;

	output = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!output)
		return (NULL);
	i = 0;
	if (s1)
		while (*s1)
			output[i++] = *(s1++);
	while (*s2)
		output[i++] = *(s2++);
	output[i] = '\0';
	return (output);
}

char	*strnjoin(char *s1, char *s2, size_t n)
{
	size_t	s1_len;
	char	*output;
	size_t	i;

	s1_len = ft_strlen(s1);
	output = malloc(s1_len + n + 1);
	if (!output)
		return (NULL);
	i = 0;
	if (s1)
		while (*s1)
			output[i++] = *(s1++);
	while (*s2 && i - s1_len < n)
		output[i++] = *(s2++);
	output[i] = '\0';
	return (output);
}
