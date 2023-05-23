/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifisnotawall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:13:33 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 13:22:42 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_create_case(t_case *caset, t_game data, char *img, char c)
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

int	ft_add_not_wall(char c, t_case *caset, t_game *data)
{
	if (c == 'E')
		return (ft_create_case(caset, *data, EXIT, c));
	if (c == 'P')
	{
		data->mc = caset;
		return (ft_create_case(caset, *data, MCFS, c));
	}
	if (c == 'C')
		return (ft_create_case(caset, *data, M2, c));
	return (ft_create_case(caset, *data, FLOOR, 0));
}
