/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:23:04 by lpalomin          #+#    #+#             */
/*   Updated: 2025/01/31 15:23:06 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif 

# include <stdlib.h>
# include <unistd.h>

char			*get_next_line(int fd);
unsigned int	ft_strlen(const char *s);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*get_text(char **buffer);
void			next_line(char	**buffer, int len);

#endif