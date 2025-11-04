/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:07:54 by elorente          #+#    #+#             */
/*   Updated: 2025/11/03 21:07:54 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i = 0;
	int		j = 0;
	int		len1 = ft_strlen(str1);
	int		len2 = ft_strlen(str2);
	char	*res = malloc(len1 + len2 + 1);

	if (!res)
		return (NULL);
	
	while (str1[i])
	{
		res[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		res[i] = str2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(char *str, char c)
{
	int	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_sobrante(char	*str)
{
	int		i = 0;
	int		j = 0;
	int		len = 0;
	char	*sobrante;

	while(str[i])
	{
		if(str[i] == '\n')
		{
			i++;
			if (!str[i])
				return(NULL);
			while (str[i + len])
				len++;
			sobrante = malloc(len + 1);
			if (!sobrante)
				return (NULL);
			while(j < len)
			{
				sobrante[j] = str[i + j];
				j++;
			}
			sobrante[j] = '\0';
			return (sobrante);
		}
		i++;
	}
	return (NULL);
}

char	*get_line(char *str)
{
	int		i = 0;
	char	*line;

	if (!str)
		return (NULL);
	
	while (str[i] && str[i] != '\n')
		i++;
	
	if (str[i] == '\n')
	{
		line = malloc(i + 2);
		if (!line)
			return (NULL);
		ft_strncpy(line, str, i + 1);
		line[i + 1] = '\0';
	}
	else
	{
		line = malloc(i + 1);
		if (!line)
			return (NULL);
		ft_strncpy(line, str, i);
		line[i] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);

	static char		*sobrante;
	char			*temp;
	char			*nuevo;
	char			*line;
	char			*buffer;
	int				leido;

	leido = 1;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

	while((sobrante == NULL || !ft_strchr(sobrante, '\n')) && leido > 0)
	{
		leido = read(fd, buffer, BUFFER_SIZE);
		if (leido < 0)
		{
			free(buffer);
			return(NULL);
		}

		buffer[leido] = '\0';

		if (sobrante)
		{
			temp = ft_strjoin(sobrante, buffer);
			free(sobrante);
			sobrante = temp;
		}
		else
			sobrante = ft_strjoin("", buffer);
	}
	free(buffer);

	if (!sobrante || !*sobrante)
		return (NULL);

	line = get_line(sobrante);
	nuevo = get_sobrante(sobrante);
	free(sobrante);
	sobrante = nuevo;
	
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);

	while((line = get_next_line(fd)) != NULL)
	{
		printf("-->%s", line);
		free(line);
	}
	close(fd);
	return (0);
}