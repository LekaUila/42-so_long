/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mc_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:17:44 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 13:41:40 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_swap_case(t_case *case1, t_case *case2)
{
	char	tempo_type;
	void	**tempo_tab_img;

	tempo_type = case1->type;
	tempo_tab_img = case1->tab_img;
	case1->tab_img = case2->tab_img;
	case1->type = case2->type;
	case2->type = tempo_type;
	case2->tab_img = tempo_tab_img;
}

void	ft_take_collectable(t_game *data, t_case *caset)
{
	mlx_destroy_image(data->id_mlx, caset->tab_img[0]);
	caset->tab_img[0] = mlx_xpm_file_to_image(data->id_mlx, FLOOR,
			&caset->width, &caset->height);
	caset->type = 0;
	data->collectable--;
}

void	ft_mc_move(t_game *data, int x, int y, char	*img)
{
	int		mc_x;
	int		mc_y;
	t_case	*n_case;

	mc_x = data->mc->x;
	mc_y = data->mc->y;
	n_case = data->listcase[mc_y + y][mc_x + x];
	if (n_case->type == 1)
		return ;
	else if (n_case->type == 'C')
		ft_take_collectable(data, n_case);
	else if (n_case->type == 'E')
	{
		if (data->collectable)
			return ;
		ft_close_game(data, 0, NULL);
	}
	data->move_count++;
	ft_swap_case(n_case, data->mc);
	data->mc = n_case;
	mlx_destroy_image(data->id_mlx, data->mc->tab_img[0]);
	data->mc->tab_img[0] = mlx_xpm_file_to_image(data->id_mlx, img,
			&data->mc->width, &data->mc->height);
}
