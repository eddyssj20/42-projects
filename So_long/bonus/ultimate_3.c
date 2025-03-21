/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorente <elorente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:17:05 by elorente          #+#    #+#             */
/*   Updated: 2025/03/20 21:16:24 by elorente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cinematic_step(t_game *game, int sleep)
{
	cinematic_frame(game, sleep);
	game->cinema_step++;
}

void	display_frames_2(t_game *game)
{
	static int	loop2 = 10;

	if (game->cinema_step >= 10 && game->cinema_step < 11)
	{
		loop_control(game, &loop2, 10, 11);
		return ;
	}
	else if (game->cinema_step >= 12 && game->cinema_step < 16)
		cinematic_step(game, 500000);
	else if (game->cinema_step >= 16 && game->cinema_step < 19)
		cinematic_step(game, 150000);
	else if (game->cinema_step >= 19)
	{
		cinematic_frame(game, 150000);
		close_game(game);
	}
}
