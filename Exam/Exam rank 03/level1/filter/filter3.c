#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER
# define BUFFER 100
#endif

void	replace(char *str, char *value)
{
	int	i = 0;
	int	j = 0;
	int printer = 0;
	int len = strlen(value);

	while(str[i])
	{
		j = 0;
		printer = 0;
		while (j < len && str[i + j] == value[j] && str[i + j])
			j++;
		if (j == len)
		{
			while (printer != len)
			{
				printf("*");
				printer++;
			}
			i += len;
		}
		else
		{
			printf("%c", str[i]);
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 2 || argv[1][0] != '\0')
	{
		printf("Error\n");
		return(1);
	}

	char	temp[BUFFER];
	char	*res = NULL;
	char	*buff;
	int		leido = 0;
	int 	b_leido = 0;
	int		i;

	while((b_leido = read(0, temp, BUFFER)) > 0)
	{
		buff = realloc(res, (size_t)b_leido + (size_t)leido + 1);
		if (!buff)
		{
			free(res);
			printf("Error\n");
			return (1);
		}

		res = buff;
		i = 0;

		while (i < b_leido)
		{
			res[leido + i] = temp[i];
			i++;
		}
		leido += b_leido;
		res[leido] = '\0';
	}
	if (b_leido < 0)
	{
		printf("Error\n");
		free(res);
		return (1);
	}
	if (!res)
		return (0);
	replace(res, argv[1]);
	free(res);
	return (0);
}