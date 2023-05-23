/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_border_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:06:00 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/11 14:16:52 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_case	*ft_make_caset_spe(int y, int x, t_game data, char *file)
{
	t_case	*caset;
	void	**v;
	int		*w;
	int		*h;

	caset = ft_calloc(sizeof(t_case), 1);
	if (!caset)
		return (NULL);
	caset->x = x;
	caset->y = y;
	v = ft_calloc(sizeof(void *), 2);
	if (!v)
	{
		free(caset);
		return (NULL);
	}
	w = &(caset->width);
	h = &(caset->height);
	v[0] = mlx_xpm_file_to_image(data.id_mlx, file, w, h);
	caset->tab_img = v;
	caset->type = 1;
	return (caset);
}

t_case	**ft_make_bottomlinecase(char ***map_skull, int y, t_game data)
{
	t_case	**linecase;
	int		x;

	x = 1;
	linecase = ft_calloc(sizeof(t_case *), ft_len_strtab(map_skull[y]) + 1);
	if (!linecase)
		return (NULL);
	linecase[0] = ft_make_caset_spe(y, 0, data, BMCBL);
	if (!(linecase[0]))
		return (linecase);
	while (map_skull[y][x + 1])
	{
		linecase[x] = ft_make_caset_spe(y, x, data, BMB);
		if (!(linecase[x]))
			return (linecase);
		x++;
	}
	linecase[x] = ft_make_caset_spe(y, x, data, BMCBR);
	return (linecase);
}

static void	ft_make_tab_top_border_map(char *tab[3][3])
{
	tab[0][0] = BML;
	tab[0][2] = BMR;
	tab[0][1] = BMT1;
	tab[1][0] = BML;
	tab[1][2] = BMR;
	tab[1][1] = BMT2;
	tab[2][0] = BML;
	tab[2][2] = BMR;
	tab[2][1] = BMT3;
}

t_case	**ft_make_toplinecase(char ***map_skull, int y, t_game data)
{
	t_case	**linecase;
	t_case	*caset;
	char	*tab[3][3];
	int		x;

	ft_make_tab_top_border_map(tab);
	x = 1;
	linecase = ft_calloc(sizeof(t_case *), ft_len_strtab(map_skull[y]) + 1);
	if (!linecase)
		return (NULL);
	linecase[0] = ft_make_caset_spe(y, 0, data, tab[y][0]);
	if (!(linecase[0]))
		return (linecase);
	while (map_skull[y][x + 1])
	{
		if (ft_iswaterfall(map_skull, x))
			caset = ft_create_water_fall(map_skull, y, x, data);
		else
			caset = ft_make_caset_spe(y, x, data, tab[y][1]);
		if (!caset)
			return (linecase);
		linecase[x++] = caset;
	}
	linecase[x] = ft_make_caset_spe(y, x, data, tab[y][2]);
	return (linecase);
}
