/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_r_c_water_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:33:28 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/11 14:16:16 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_create_tab_r_c_water(char *tab[12])
{
	tab[0] = WWRCBL1;
	tab[1] = WWRCBL2;
	tab[2] = WWRCBL3;
	tab[3] = WWRCBR1;
	tab[4] = WWRCBR2;
	tab[5] = WWRCBR3;
	tab[6] = WWRCTL1;
	tab[7] = WWRCTL2;
	tab[8] = WWRCTL3;
	tab[9] = WWRCTR1;
	tab[10] = WWRCTR2;
	tab[11] = WWRCTR3;
}

static int	ft_cond_r_c_water(char ***map_sku, t_case *caset)
{
	if (map_sku[caset->y + 1][caset->x - 1][0] != '1')
		return (0);
	else if (map_sku[caset->y + 1][caset->x + 1][0] != '1')
		return (3);
	else if (map_sku[caset->y - 1][caset->x - 1][0] != '1')
		return (6);
	else if (map_sku[caset->y - 1][caset->x + 1][0] != '1')
		return (9);
	return (-1);
}

int	ft_check_r_c_w(char ***map_sku, t_case *caset, t_game data, int water)
{
	char	*tab[12];
	int		ind;
	void	**v;
	int		*w;
	int		*h;

	ft_create_tab_r_c_water(tab);
	ind = ft_cond_r_c_water(map_sku, caset);
	if (ind != -1 && water == 8)
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
	return (ft_check_b_w(map_sku, caset, data, water));
}
