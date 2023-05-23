/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichemap_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:52:03 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/15 13:34:30 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_affichecase(t_game data, int y, int x, int anime)
{
	int	ind;

	if (data.listcase[y][x]->tab_img != NULL)
	{
		ind = data.listcase[y][x]->anime;
		if (data.listcase[y][x]->tab_img[ind] == NULL)
		{
			data.listcase[y][x]->anime = 0;
			ind = 0;
		}
		if (data.listcase[y][x]->tab_img[ind] != NULL)
		{
			mlx_put_image_to_window(data.id_mlx, data.window,
				data.listcase[y][x]->tab_img[ind],
				10 + (x * 32), 115 + (y * 32));
		}
		if (anime)
			data.listcase[y][x]->anime++;
	}
}

static void	ft_afficheline(t_game data, int y, int anime)
{
	int		x;

	x = 0;
	while (data.listcase[y][x])
	{
		ft_affichecase(data, y, x, anime);
		x++;
	}
}

void	ft_affichemap(t_game data, int anime)
{
	int		y;

	y = 0;
	while (data.listcase[y])
	{
		ft_afficheline(data, y, anime);
		y++;
	}
}
