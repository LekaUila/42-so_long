/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichemap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:52:03 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 12:53:57 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_affichecase(t_game data, int y, int x)
{
	if (data.listcase[y][x]->tab_img != NULL)
	{
		if (data.listcase[y][x]->tab_img[0] != NULL)
		{
			mlx_put_image_to_window(data.id_mlx, data.window,
				data.listcase[y][x]->tab_img[0], 10 + (x * 32), 25 + (y * 32));
		}
	}
}

static void	ft_afficheline(t_game data, int y)
{
	int		x;

	x = 0;
	while (data.listcase[y][x])
	{
		ft_affichecase(data, y, x);
		x++;
	}
}

void	ft_affichemap(t_game data)
{
	int		y;

	y = 0;
	while (data.listcase[y])
	{
		ft_afficheline(data, y);
		y++;
	}
}
