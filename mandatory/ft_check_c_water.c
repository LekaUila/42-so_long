/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_c_water.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:33:28 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 13:01:19 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_create_tab_c_water(char *tab[12])
{
	tab[0] = WWCBL1;
	tab[1] = WWCBL2;
	tab[2] = WWCBL3;
	tab[3] = WWCBR1;
	tab[4] = WWCBR2;
	tab[5] = WWCBR3;
	tab[6] = WWCTL1;
	tab[7] = WWCTL2;
	tab[8] = WWCTL3;
	tab[9] = WWCTR1;
	tab[10] = WWCTR2;
	tab[11] = WWCTR3;
}

static int	ft_cond_c_water(char ***map_sku, t_case *caset)
{
	int	top;
	int	bottom;
	int	right;
	int	left;

	top = (map_sku[caset->y - 1][caset->x][0] == '1');
	bottom = (map_sku[caset->y + 1][caset->x][0] == '1');
	right = (map_sku[caset->y][caset->x + 1][0] == '1');
	left = (map_sku[caset->y][caset->x - 1][0] == '1');
	if (right && top && (map_sku[caset->y - 1][caset->x + 1][0]) == '1')
		return (0);
	else if (left && top && (map_sku[caset->y - 1][caset->x - 1][0]) == '1')
		return (3);
	else if (right && bottom && map_sku[caset->y + 1][caset->x + 1][0] == '1')
		return (6);
	else if (left && bottom && (map_sku[caset->y + 1][caset->x - 1][0]) == '1')
		return (9);
	return (-1);
}

int	ft_check_c_w(char ***map_sku, t_case *caset, t_game data, int water)
{
	char	*tab[12];
	int		ind;
	void	**v;
	int		*w;
	int		*h;

	ft_create_tab_c_water(tab);
	ind = ft_cond_c_water(map_sku, caset);
	if (ind != -1 && water >= 4)
	{
		v = ft_calloc(sizeof(void *), 4);
		if (!v)
			return (0);
		w = &(caset->width);
		h = &(caset->height);
		v[0] = mlx_xpm_file_to_image(data.id_mlx, tab[ind], w, h);
		v[1] = mlx_xpm_file_to_image(data.id_mlx, tab[ind + 1], w, h);
		v[2] = mlx_xpm_file_to_image(data.id_mlx, tab[ind + 2], w, h);
		caset->tab_img = v;
		caset->type = 1;
		return (1);
	}
	return (ft_create_simple_wall(caset, data));
}
