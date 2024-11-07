/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derandri <derandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:48:49 by derandri          #+#    #+#             */
/*   Updated: 2024/03/14 08:41:42 by derandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		size;

	size = ft_strlen(src);
	dest = (char *)malloc(size + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	dest[size] = 0;
	while (--size >= 0)
		dest[size] = src[size];
	return (dest);
}

size_t	ft_strlen(const char *len)
{
	size_t	i;

	i = 0;
	while (len[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	letter;
	int				i;

	i = 0;
	letter = (unsigned char)c;
	while (str[i] != '\0')
	{
		if (str[i] == letter)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == letter)
		return ((char *)(str + i));
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	j = ft_strlen(s1);
	i = ft_strlen(s2);
	new = (char *)malloc((i + j + 1) * sizeof(char));
	if (!new)
		return (0);
	ft_strlcpy(new, s1, j + 1);
	ft_strlcpy((new + j), s2, i + 1);
	free ((void *)(s1));
	return (new);
}
