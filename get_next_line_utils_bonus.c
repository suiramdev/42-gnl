/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:23:28 by mnouchet          #+#    #+#             */
/*   Updated: 2022/11/29 18:50:26 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
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

static void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	bytes = nmemb * size;
	if (bytes / size != nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr)
		ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
