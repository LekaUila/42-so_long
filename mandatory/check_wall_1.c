/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:06:29 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 12:48:19 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_create_simple_wall(t_case *caset, t_game data)
{
	void	**v;
	int		*w;
	int		*h;

	v = ft_calloc(sizeof(void *), 2);
	if (!v)
		return (0);
	w = &(caset->width);
	h = &(caset->height);
	v[0] = mlx_xpm_file_to_image(data.id_mlx, WS, w, h);
	caset->tab_img = v;
	caset->type = 1;
	return (1);
}

int	ft_check_full_w(char ***map_sku, t_case *caset, t_game data, int water)
{
	void	**v;
	int		*w;
	int		*h;

	if (water == 9)
	{
		v = ft_calloc(sizeof(void *), 4);
		if (!v)
			return (0);
		w = &(caset->width);
		h = &(caset->height);
		v[0] = mlx_xpm_file_to_image(data.id_mlx, WWM1, w, h);
		v[1] = mlx_xpm_file_to_image(data.id_mlx, WWM2, w, h);
		v[2] = mlx_xpm_file_to_image(data.id_mlx, WWM3, w, h);
		caset->tab_img = v;
		caset->type = 1;
		return (1);
	}
	return (ft_check_r_c_w(map_sku, caset, data, water));
}
