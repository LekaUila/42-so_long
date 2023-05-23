/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifisnotawall_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:13:33 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/15 13:46:56 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_create_case(t_case *caset, t_game data, char *img, char c)
{
	void	**v;
	int		*w;
	int		*h;

	v = ft_calloc(sizeof(void *), 2);
	if (!v)
		return (0);
	w = &(caset->width);
	h = &(caset->height);
	v[0] = mlx_xpm_file_to_image(data.id_mlx, img, w, h);
	caset->tab_img = v;
	caset->type = c;
	return (1);
}

static int	ft_create_mush(t_case *caset, t_game data, char c)
{
	void	**v;
	int		*w;
	int		*h;

	v = ft_calloc(sizeof(void *), 5);
	if (!v)
		return (0);
	w = &(caset->width);
	h = &(caset->height);
	v[0] = mlx_xpm_file_to_image(data.id_mlx, M1, w, h);
	v[1] = mlx_xpm_file_to_image(data.id_mlx, M2, w, h);
	v[2] = mlx_xpm_file_to_image(data.id_mlx, M3, w, h);
	v[3] = mlx_xpm_file_to_image(data.id_mlx, M2, w, h);
	caset->tab_img = v;
	caset->type = c;
	return (1);
}

static int	ft_create_mc(t_case *caset, t_game data, char c)
{
	void	**v;
	int		*w;
	int		*h;

	v = ft_calloc(sizeof(void *), 5);
	if (!v)
		return (0);
	w = &(caset->width);
	h = &(caset->height);
	v[0] = mlx_xpm_file_to_image(data.id_mlx, MCFS, w, h);
	v[1] = mlx_xpm_file_to_image(data.id_mlx, MCFW1, w, h);
	v[2] = mlx_xpm_file_to_image(data.id_mlx, MCFS, w, h);
	v[3] = mlx_xpm_file_to_image(data.id_mlx, MCFW2, w, h);
	caset->tab_img = v;
	caset->type = c;
	return (1);
}

int	ft_add_not_wall(char c, t_case *caset, t_game *data)
{
	if (c == 'E')
		return (ft_create_case(caset, *data, EXIT, c));
	if (c == 'P')
	{
		data->mc = caset;
		return (ft_create_mc(caset, *data, c));
	}
	if (c == 'C')
		return (ft_create_mush(caset, *data, c));
	if (c == '0')
		return (ft_create_case(caset, *data, FLOOR, 0));
	return (ft_create_case_ennemis(c, caset, data));
}
