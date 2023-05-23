/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:37:15 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/15 13:43:51 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_key_hook(int keycode, void *param)
{
	t_game	*data;

	data = (t_game *) param;
	if (keycode == 65307)
		ft_close_game(data, 0, NULL);
	if (keycode == 65362)
		ft_mc_move(data, 0, -1, 0);
	else if (keycode == 65364)
		ft_mc_move(data, 0, 1, 3);
	else if (keycode == 65361)
		ft_mc_move(data, -1, 0, 1);
	else if (keycode == 65363)
		ft_mc_move(data, 1, 0, 2);
	return (1);
}

int	ft_other_hook(void *param)
{
	t_game	*data;
	clock_t	timet;
	double	duration;

	data = (t_game *) param;
	timet = clock();
	duration = (double)(timet - data->last_time);
	if (duration >= 50000)
	{
		ft_affichemap(*data, 1);
		ft_affiche_compteur(data, data->move_count);
		data->last_time = clock();
	}
	ft_affichemap(*data, 0);
	return (1);
}
/*
keyboard code : 

esc          : 65307
top arrow    : 65362
bottom arrow : 65364
left arrow   : 65361
right arrow  : 65363
*/

int	ft_hook_window_destroy(void	*param)
{
	t_game	*data;

	data = (t_game *) param;
	ft_close_game(data, 0, NULL);
	return (1);
}
