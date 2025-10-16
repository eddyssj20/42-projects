/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:15:54 by elorente          #+#    #+#             */
/*   Updated: 2025/10/16 14:15:54 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//convierte un negativo en positivo
int valor_absoluto(int x)
{
    if (x < 0)
		return -x;
    return x;
}

/*printea las soluciones
Primero printea la columna por fila,
Si hay columna + 1, se printea un espacio
Si no hay, se sale del while y printea salto de linea
*/
void print_solution(int *rows, int n)
{
    int col = 0;
    while (col < n)
    {

        printf("%d", rows[col]);
        if (col + 1 < n)
            printf(" ");
        col++;
    }
    printf("\n");
}

/*Es posible colocar una queen en esta posicion?
*/
int posible(int *rows, int col, int row)
{
    int c = 0;
    while (c < col)
    {
        int r = rows[c];
        // misma fila
        if (r == row)
            return 0;
        // misma diagonal: |row - r| == |col - c|
        if (valor_absoluto(row - r) == valor_absoluto(col - c))
            return 0;
        c++;
    }
    return 1;
}

// Backtracking: intentamos colocar reina en cada fila de la columna 'col'
void solve(int *rows, int n, int col)
{
    int row;

    if (col == n)
    {
        // tenemos una solución completa: imprimir filas por columna
        print_solution(rows, n);
        return;
    }

    row = 0;
    while (row < n)
    {
        if (posible(rows, col, row))
        {
            rows[col] = row;          // colocar reina en (row, col)
            solve(rows, n, col + 1);  // siguiente columna
            // backtrack: opcional poner -1, pero no es estrictamente necesario
            // rows[col] = -1;
        }
        row++;
    }
}

int main(int argc, char *argv[])
{
    int n;
    int *rows;
    int i;

    if (argc != 2)
    {
        printf("Error");
        return 1;
    }

    n = atoi(argv[1]);
    //Convertimos el char a int y verificamos negativos
    if (n <= 0)
        return 0;

    rows = malloc(100);
    if (rows == NULL)
    {
        printf("Error: malloc\n");
        return 1;
    }
    i = 0;
    while (i < n)
    {
        rows[i] = -1;
        i++;
    }

    solve(rows, n, 0);

    free(rows);
    return 0;
}
