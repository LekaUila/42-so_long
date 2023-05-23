/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_water_fall.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:05:10 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 13:20:01 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_iswaterfall(char ***map_skull, int x)
{
	int	b;

	if (map_skull[1][x][0] == '1')
	{
		b = (map_skull[1][x - 1][0] == '1');
		b += (map_skull[1][x + 1][0] == '1');
		if (b)
			return (1);
	}
	return (0);
}

static void	ft_create_tab_wf_bis(char *tab[3][3][3])
{
	tab[2][0][0] = WFBBL1;
	tab[2][0][1] = WFBBL2;
	tab[2][0][2] = WFBBL3;
	tab[2][1][0] = WFBM1;
	tab[2][1][1] = WFBM2;
	tab[2][1][2] = WFBM3;
	tab[2][2][0] = WFBBR1;
	tab[2][2][1] = WFBBR2;
	tab[2][2][2] = WFBBR3;
}

static void	ft_create_tab_wf(char *tab[3][3][3])
{
	tab[0][0][0] = WFTBL1;
	tab[0][0][1] = WFTBL2;
	tab[0][0][2] = WFTBL3;
	tab[0][1][0] = WFTM1;
	tab[0][1][1] = WFTM2;
	tab[0][1][2] = WFTM3;
	tab[0][2][0] = WFTBR1;
	tab[0][2][1] = WFTBR2;
	tab[0][2][2] = WFTBR3;
	tab[1][0][0] = WFMBL1;
	tab[1][0][1] = WFMBL2;
	tab[1][0][2] = WFMBL3;
	tab[1][1][0] = WFMM1;
	tab[1][1][1] = WFMM2;
	tab[1][1][2] = WFMM3;
	tab[1][2][0] = WFMBR1;
	tab[1][2][1] = WFMBR2;
	tab[1][2][2] = WFMBR3;
	ft_create_tab_wf_bis(tab);
}

static void	ft_give_file(char ***map_skull, int y, int x, char *file[3])
{
	char	*tab[3][3][3];
	int		l;
	int		r;

	l = (map_skull[1][x - 1][0] == '1');
	r = (map_skull[1][x + 1][0] == '1');
	ft_create_tab_wf(tab);
	if (r && l)
	{
		file[0] = tab[y][1][0];
		file[1] = tab[y][1][1];
		file[2] = tab[y][1][2];
	}
	else if (r)
	{
		file[0] = tab[y][0][0];
		file[1] = tab[y][0][1];
		file[2] = tab[y][0][2];
	}
	else if (l)
	{
		file[0] = tab[y][2][0];
		file[1] = tab[y][2][1];
		file[2] = tab[y][2][2];
	}
}

t_case	*ft_create_water_fall(char ***map_skull, int y, int x, t_game data)
{
	t_case	*caset;
	void	**v;
	int		*w;
	int		*h;
	char	*file[3];

	ft_give_file(map_skull, y, x, file);
	caset = ft_calloc(sizeof(t_case), 1);
	if (!caset)
		return (NULL);
	caset->x = x;
	caset->y = y;
	v = ft_calloc(sizeof(void *), 4);
	if (!v)
		return (0);
	w = &(caset->width);
	h = &(caset->height);
	v[0] = mlx_xpm_file_to_image(data.id_mlx, file[0], w, h);
	v[1] = mlx_xpm_file_to_image(data.id_mlx, file[1], w, h);
	v[2] = mlx_xpm_file_to_image(data.id_mlx, file[2], w, h);
	caset->tab_img = v;
	caset->type = 1;
	return (caset);
}
