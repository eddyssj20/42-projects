#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

int		ft_strlen(char	*str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char	*str, char	c)
{
	int	i = 0;

	while(str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i = 0;
	int		j = 0;
	int		len1 = ft_strlen(str1);
	int		len2 = ft_strlen(str2);
	char	*joined = malloc(len1 + len2 + 1);

	while(str1[i])
	{
		joined[i] = str1[i];
		i++;
	}
	while(str2[j])
	{
		joined[i] = str2[j];
		i++;
		j++;
	}
	joined[i] = '\0';
	return (joined);
}

char	*ft_strncpy(char *dest, char *src, int size)
{
	int	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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

char	*get_sobrante(char *str)
{
	int		i = 0;
	int		j = 0;
	int		len = 0;
	char	*sobrante;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			if (!str[i])
				return (NULL);
			while(str[i + len])
				len++;
			sobrante = malloc(len + 1);
			if (!sobrante)
				return (NULL);
			while (str[i])
			{
				sobrante[j] = str[i];
				j++;
				i++;
			}
			sobrante[j] = '\0';
			return (sobrante);
		}
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*sobrante;
	char		*result;
	char		*temp;
	char		*linea;
	char		*nuevo;
	int			leido;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	result = malloc(BUFFER_SIZE + 1);
	if (!result)
		return (NULL);
	
	leido = 1;
	
	while((sobrante == NULL ||!ft_strchr(sobrante, '\n')) && leido > 0)
	{
		leido = read(fd, result, BUFFER_SIZE);
		if (leido < 0)
		{
			free(result);
			return (NULL);
		}

		result[leido] = '\0';

		if (sobrante)
		{
			temp = ft_strjoin(sobrante, result);
			free(sobrante);
			sobrante = temp;
		}
		else
			sobrante = ft_strjoin("", result);
	}
	free(result);

	if (!sobrante || !*sobrante)
		return (NULL);

	linea = get_line(sobrante);
	nuevo = get_sobrante(sobrante);
	free(sobrante);
	sobrante = nuevo;
	return (linea);
}


int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error al abrir el archivo");
        return (1);
    }

	printf("Ejecutando main\n");
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}