/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:59:46 by elorente          #+#    #+#             */
/*   Updated: 2025/11/04 17:11:41 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	print_board(int *board, int n)
{
	int i = 0;
	while (i < n)
	{
		fprintf(stdout, "%d", board[i]);
		if (i < n - 1)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

int is_safe(int *board, int x, int y)
{
	int i = 0;
	while (i < x)
	{
		if ((board[i] == y) || (board[i] - y == x - i) || (y - board[i] == x -i))
			return (0);
		i++;
	}
	return(1);
}

void place_queens(int *board, int x, int n)
{
	if (x == n)
	{
		print_board(board, n);
		return ;
	}

	int y = 0;
	while (y < n)
	{
		if (is_safe(board, x, y))
		{
			board[x] = y;
			place_queens(board, x + 1, n);
		}
		y++;
	}
}

void solve_queens(int n)
{
	int *board = malloc(n * sizeof(int));
	if (!board)
		return;
	place_queens(board, 0, n);
	free(board);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	int n = atoi(argv[1]);
	if (!n || n < 0)
		return(1);
	solve_queens(n);
	return(0);
}