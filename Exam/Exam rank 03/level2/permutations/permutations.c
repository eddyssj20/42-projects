/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:21:25 by elorente          #+#    #+#             */
/*   Updated: 2025/10/13 18:45:07 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//strlen para siempre tener el len de mis strings
int	ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

//is alpha para comprobar que solo recibo letras
int	ft_isalpha(char	c)
{
	if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
		return (0);
	return (1);
}

//Para hacer el cambio
void	ft_swap(char *a, char *b)
{
	char	temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//Para verificar que no se  repite la letra
int ft_strchr(char *str, char c)
{
	int	i;
	i = 0;
	while(str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*El order funciona de la siguiente manera
1. Tomo el len de la str que recibo
2. Entro en un bucle de swap
3. recorro la string dentro del bucle en pares, comparando si uno es mayor que el siguiente
4. Si el i+1 es mayor que i, hago swap y swap = 1 para recorrer la string las veces que sea necesario
5. cuando la str este ordenada, swap = 0, termino y retorno str*/
char	*order(char *str)
{
	int	len;
	int swap;
	int	i;

	//1.
	len = ft_strlen(str);
	swap = 1;
	//swap se inicializa en 1 porque asumimos que va a haber un cambio, si no lo hay, esta cambia a 0

	//2.
	while (swap)
	{
		swap = 0;
		i = 0;
		while (i < len - 1)
		{
			//3.
			if (str[i] > str[i + 1])
			{
				//4.
				ft_swap(&str[i], &str[i + 1]);
				swap = 1;
			}
			i++;
		}
	}
	//5.
	return(str);
}


/*Permutate toma una str source y una result, una posicion dentro del result y hace backtracking,
se llama a si misma hasta que haya permutado todas las veces posibles*/
void	permutate(char	*source, char *result, int pos)
{
	int	slen;
	slen = ft_strlen(source);
	int	i = 0;

	//en el ultimo backtraking, la posicion es igual a len, osea que ya recorrio todo y esta permutada, por lo tanto, con write escribimos el resultado y retornamos
	if (pos == slen)
	{
		write (1, result, slen);
		write(1, "\n", 1);
		return;
	}
	
	/*Mientras el iterador sea menor que len primero revisamos que la letra a usar no la hayamos usado antes
	si esta bien, pues en la resultado de [i] ponemos la letra que es source de [i]
	volvemos a permutar pero ahora con pos + 1, para ordenar la siguiente letra
	cuando termine la primera permutacion, se printea en el pos == slen y aumentamos i++ para que la siguiente permutacion comienze con la segunda letra */
	while (i < slen)
	{
		if (!ft_strchr(result, source[i]))
		{
			result[pos] = source[i];
			permutate(source, result, pos + 1);
			result[pos] = '\0';
		}
		i++;
	}
}


/*El main primero hacemos nuestras validaciones
Que sean 2 argumentos
Que no sea una string vacia o solo con espacios
Que toda sea letras
Creamos 2 char *
*res que es el resultado y es = malloc(len + 1)
*source que es el order(argv[1])
y permutamos con el source, res y posicion inicial 0
liberamos res con free
Return (0)*/
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	if (ft_strlen(argv[1]) == 0 || argv[1][0] == ' ' && !argv[1][1])
		return(0);
	int	i = 0;
	while (argv[1][i])
	{
		if (ft_isalpha(argv[1][i]))
			return (0);
		i++;
	}
	int	len = ft_strlen(argv[1]);

	char	*res = malloc(len + 1);
	if (!res)
		return (1);
	char	*source;
	source = order(argv[1]);
	permutate(source, res, 0);
	free (res);
	return (0);
}