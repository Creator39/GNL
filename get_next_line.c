/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derandri <derandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:46:53 by derandri          #+#    #+#             */
/*   Updated: 2024/03/18 08:38:04 by derandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_stock(char *stock)
{
	int		len;
	int		i;
	char	*new_stock;

	len = 0;
	i = 0;
	if (stock == NULL)
		return (NULL);
	while (stock[len] != '\n' && stock[len])
		len++;
	if (stock[len] == '\n')
		len++;
	new_stock = malloc((ft_strlen(stock) - len + 1) * sizeof(char));
	if (!new_stock)
		return (NULL);
	while (stock[len + i])
	{
		new_stock[i] = stock[len + i];
		i++;
	}
	free(stock);
	new_stock[i] = '\0';
	return (new_stock);
}

char	*to_the_line(char *stock, char *line)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (stock == NULL)
		return (NULL);
	while (stock[len] != '\n' && stock[len])
		len++;
	if (stock[len] == '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*stock_in_stock(int fd, char *stock, char *buffer)
{
	ssize_t	read_fd;

	read_fd = 1;
	if (!stock)
		stock = ft_strdup("");
	while (read_fd > 0)
	{
		read_fd = read(fd, buffer, BUFFER_SIZE);
		if (read_fd == -1)
		{
			free(buffer);
			free((void *)stock);
			return (NULL);
		}
		buffer[read_fd] = '\0';
		stock = ft_strjoin(stock, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;
	char		*buffer;

	line = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (stock);
		free (buffer);
		stock = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	stock = stock_in_stock(fd, stock, buffer);
	if (stock == NULL || *stock == 0)
	{
		free (stock);
		return (stock = 0);
	}
	line = to_the_line(stock, line);
	stock = new_stock(stock);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*str;

	fd = open("10-bg.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		printf("%s", str);
		free(str);
	}
	close(fd);
}*/
