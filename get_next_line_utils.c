/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:22:37 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/31 15:22:39 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(const char *s)
{
	size_t	cont;

	cont = 0;
	if (s == NULL)
		return (0);
	//printf("> Comp. strlen: %s\n", s);
	while (s[cont] != '\0')
		cont++;
	return (cont);
}

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size)
{
	unsigned int	cont;

	cont = 0;
	if (size > 0)
	{
		while (src[cont] != '\0' && cont < size - 1)
		{
			dst[cont] = src[cont];
			cont++;
		}
		dst[cont] = '\0';
	}
	while (src[cont] != '\0')
		cont++;
	return (cont);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcpy(str + len1, s2, len2 + 1);
	return (str);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	cont;
	char	*str_cpy;

	size = 0;
	cont = 0;
	if (!s)
		return (NULL);
	while (s[size] != '\0')
		size++;
	str_cpy = (char *)malloc(size + 1);
	if (str_cpy == NULL)
		return (NULL);
	while (cont < size) 
	{
		str_cpy[cont] = s[cont];
		cont++;
	}
	str_cpy[cont] = '\0';
	return (str_cpy);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*aux;

	aux = NULL;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			aux = (char *)s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (aux);
}

char	*get_line(char **buffer)
{
	int		cont;
	int		len;
	char	*line;

	len = 0;
	cont = 0;
	if (!buffer || !*buffer)
		return (NULL);
	while ((*buffer)[len] && (*buffer)[len] != '\n')
		len++;
	line = (char *)malloc((len + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (cont < len)
	{
		line[cont] = (*buffer)[cont];
		cont++;
	}
	if ((*buffer)[len] == '\n')
	{
		line[len] = '\n';
		len++;
		next_line(buffer, len);
	}
	line[len] = '\0';
	return (line);
}

void	next_line(char	**buffer, int len)
{
	char	*new_buffer;

	new_buffer = ft_strdup(*buffer + len);
	if (!new_buffer)
		return ;
	free(*buffer);
	*buffer = new_buffer;
	printf("> buffer: %s\n", *buffer);
}
