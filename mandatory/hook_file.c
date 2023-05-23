/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:37:15 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 13:22:22 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, void *param)
{
	t_game	*data;

	data = (t_game *) param;
	(void) param;
	if (keycode == 65307)
		ft_close_game(data, 0, NULL);
	if (keycode == 65362)
		ft_mc_move(data, 0, -1, MCBS);
	else if (keycode == 65364)
		ft_mc_move(data, 0, 1, MCFS);
	else if (keycode == 65361)
		ft_mc_move(data, -1, 0, MCLS);
	else if (keycode == 65363)
		ft_mc_move(data, 1, 0, MCRS);
	ft_affichemap(*data);
	ft_printf("Status :\nCollectable in map : %i\nNumber of Move : %i\n\n",
		data->collectable, data->move_count);
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
