/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_b_water.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:33:28 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 12:57:54 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_create_tab_b_water(char *tab[12])
{
	tab[0] = WWBB1;
	tab[1] = WWBB2;
	tab[2] = WWBB3;
	tab[3] = WWBT1;
	tab[4] = WWBT2;
	tab[5] = WWBT3;
	tab[6] = WWBL1;
	tab[7] = WWBL2;
	tab[8] = WWBL3;
	tab[9] = WWBR1;
	tab[10] = WWBR2;
	tab[11] = WWBR3;
}

static int	ft_cond_b_water(char ***map_sku, t_case *caset, int water)
{
	int	t;
	int	l;
	int	r;
	int	b;

	t = (map_sku[caset->y - 1][caset->x][0] != '1');
	t += (map_sku[caset->y - 1][caset->x - 1][0] != '1');
	l = (map_sku[caset->y][caset->x - 1][0] != '1');
	l += (map_sku[caset->y - 1][caset->x - 1][0] != '1');
	r = (map_sku[caset->y][caset->x + 1][0] != '1');
	r += (map_sku[caset->y - 1][caset->x + 1][0] != '1');
	b = (map_sku[caset->y + 1][caset->x][0] != '1');
	b += (map_sku[caset->y + 1][caset->x - 1][0] != '1');
	if (b + (map_sku[caset->y + 1][caset->x + 1][0] != '1') + water == 9)
		return (0);
	else if (t + (map_sku[caset->y - 1][caset->x + 1][0] != '1') + water == 9)
		return (3);
	else if (l + (map_sku[caset->y + 1][caset->x - 1][0] != '1') + water == 9)
		return (6);
	else if (r + (map_sku[caset->y + 1][caset->x + 1][0] != '1') + water == 9)
		return (9);
	return (-1);
}

int	ft_check_b_w(char ***map_sku, t_case *caset, t_game data, int water)
{
	char	*tab[12];
	int		ind;
	void	**v;
	int		*w;
	int		*h;

	ft_create_tab_b_water(tab);
	ind = ft_cond_b_water(map_sku, caset, water);
	if (ind != -1 && water >= 6)
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
	return (ft_check_c_w(map_sku, caset, data, water));
}
