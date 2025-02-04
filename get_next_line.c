/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:22:09 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/31 15:22:11 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		bf_read[BUFFER_SIZE + 1];
	char		*aux_to_free;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	bytes_read = read(fd, bf_read, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		bf_read[bytes_read] = '\0';
		aux_to_free = buffer;
		buffer = ft_strjoin(buffer, bf_read);
		free(aux_to_free);
		aux_to_free = NULL;
		if (ft_strrchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, bf_read, BUFFER_SIZE);
	}
	if (bytes_read <= 0 && buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	if (!buffer || *buffer == '\0')
		return (NULL);
	return (get_line(&buffer));
}
