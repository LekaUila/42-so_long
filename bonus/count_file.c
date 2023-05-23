/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:01:12 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/15 13:44:47 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_create_tab_count(t_game	*data)
{
	int	w;
	int	h;

	data->tab[0] = mlx_xpm_file_to_image(data->id_mlx, ZERO, &w, &h);
	data->tab[1] = mlx_xpm_file_to_image(data->id_mlx, ONE, &w, &h);
	data->tab[2] = mlx_xpm_file_to_image(data->id_mlx, TWO, &w, &h);
	data->tab[3] = mlx_xpm_file_to_image(data->id_mlx, THREE, &w, &h);
	data->tab[4] = mlx_xpm_file_to_image(data->id_mlx, FOUR, &w, &h);
	data->tab[5] = mlx_xpm_file_to_image(data->id_mlx, FIVE, &w, &h);
	data->tab[6] = mlx_xpm_file_to_image(data->id_mlx, SIX, &w, &h);
	data->tab[7] = mlx_xpm_file_to_image(data->id_mlx, SEVEN, &w, &h);
	data->tab[8] = mlx_xpm_file_to_image(data->id_mlx, EIGHT, &w, &h);
	data->tab[9] = mlx_xpm_file_to_image(data->id_mlx, NINE, &w, &h);
}

void	ft_clear_tab_count(t_game *data)
{
	int	i;

	i = 0;
	while (i != 10)
	{
		mlx_destroy_image(data->id_mlx, data->tab[i]);
		i++;
	}
}

int	ft_affiche_compteur(t_game *data, int nb)
{
	int	x;

	x = 0;
	if (nb < 10)
	{
		mlx_put_image_to_window(data->id_mlx, data->window,
			data->tab[nb], x, 0);
		return (50);
	}
	x = ft_affiche_compteur(data, nb / 10);
	nb = nb % 10;
	mlx_put_image_to_window(data->id_mlx, data->window, data->tab[nb], x, 0);
	return (x + 50);
}
