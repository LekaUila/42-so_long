/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mc_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:17:44 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/15 14:25:16 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_swap_case(t_case *case1, t_case *case2)
{
	char	tempo_type;
	void	**tempo_tab_img;
	int		tempo_anime;

	tempo_anime = case1->anime;
	tempo_type = case1->type;
	tempo_tab_img = case1->tab_img;
	case1->anime = case2->anime;
	case1->tab_img = case2->tab_img;
	case1->type = case2->type;
	case2->type = tempo_type;
	case2->tab_img = tempo_tab_img;
	case2->anime = tempo_anime;
}

static void	ft_take_collectable(t_game *data, t_case *caset)
{
	mlx_destroy_image(data->id_mlx, caset->tab_img[0]);
	mlx_destroy_image(data->id_mlx, caset->tab_img[1]);
	mlx_destroy_image(data->id_mlx, caset->tab_img[2]);
	mlx_destroy_image(data->id_mlx, caset->tab_img[3]);
	caset->tab_img[0] = mlx_xpm_file_to_image(data->id_mlx, FLOOR,
			&caset->width, &caset->height);
	caset->tab_img[1] = NULL;
	caset->tab_img[2] = NULL;
	caset->tab_img[3] = NULL;
	caset->type = 0;
	data->collectable--;
}

static void	ft_create_tab_mc(char *tab[4], int dir)
{
	if (dir == 0)
	{
		tab[0] = MCBS;
		tab[1] = MCBW1;
		tab[2] = MCBS;
		tab[3] = MCBW2;
	}
	if (dir == 1)
	{
		tab[0] = MCLS;
		tab[1] = MCLW1;
		tab[2] = MCLS;
		tab[3] = MCLW2;
	}
	if (dir == 2)
	{
		tab[0] = MCRS;
		tab[1] = MCRW1;
		tab[2] = MCRS;
		tab[3] = MCRW2;
	}
}

static void	ft_restart_mc_img(t_game *data, int dir)
{
	char	*tab[4];
	int		i;

	i = 0;
	if (dir == 3)
	{
		tab[0] = MCFS;
		tab[1] = MCFW1;
		tab[2] = MCFS;
		tab[3] = MCFW2;
	}
	else
		ft_create_tab_mc(tab, dir);
	while (i != 4)
	{
		mlx_destroy_image(data->id_mlx, data->mc->tab_img[i]);
		data->mc->tab_img[i] = mlx_xpm_file_to_image(data->id_mlx, tab[i],
				&data->mc->width, &data->mc->height);
		i++;
	}
}

void	ft_mc_move(t_game *data, int x, int y, int dir)
{
	int		mc_x;
	int		mc_y;
	t_case	*n_case;

	mc_x = data->mc->x;
	mc_y = data->mc->y;
	n_case = data->listcase[mc_y + y][mc_x + x];
	if (n_case->type == 1)
		return ;
	ft_ennemis_move(data);
	if (n_case->type == 'C')
		ft_take_collectable(data, n_case);
	else if (n_case->type == 'E')
	{
		if (data->collectable)
			return ;
		ft_win(data);
	}
	else if (n_case->type == 'D')
		ft_lose(data);
	data->move_count++;
	ft_swap_case(n_case, data->mc);
	data->mc = n_case;
	ft_restart_mc_img(data, dir);
}
