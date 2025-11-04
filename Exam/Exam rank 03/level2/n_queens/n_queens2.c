/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:48:33 by elorente          #+#    #+#             */
/*   Updated: 2025/11/04 12:48:33 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	is_safe(int *board, int x, int y)
{
	int	i = 0;
	while (i < x)
	{
		if (board[i] == y || (board[i] - y == x - i) || (y - board[i] == x- i))
			return (0);
		i++;
	}
	return(1);
}

void	print_board(int *board, int n)
{
	int	i = 0;

	while (i < n)
	{
		fprintf(stdout, "%d", board[i]);
		if (i < n - 1)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

void	place_queen(int *board, int col, int n)
{
	if (col == n)
	{
		print_board(board, n);
		return ;
	}

	int row = 0;
	while (row < n)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			place_queen(board, col + 1, n);
		}
		row++;
	}
}

void	solve_queen(int n)
{
	int	*board = malloc(n * sizeof(int));
	if (!board)
		return;
	place_queen(board, 0, n);
	free(board);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	int n = atoi(argv[1]);
	if (n < 1)
		return (1);

	solve_queen(n);
	return (0);
}