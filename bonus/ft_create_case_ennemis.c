/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_case_ennemis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:52:13 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/15 14:13:52 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_ennemis_exist(char c, t_ennemis **list_ennemis)
{
	int	ind;

	ind = 0;
	while (list_ennemis[ind])
	{
		if (list_ennemis[ind]->c == c)
			return (ind);
		ind++;
	}
	return (-1);
}

static void	ft_feed_ennemis(t_list *n, t_ennemis *ennemis, char c)
{
	ennemis->list_coor = n;
	ennemis->elt = c % 2;
	ennemis->c = c;
}

static int	ft_add_ennemis(t_list *n, t_game *data, char c)
{
	t_ennemis	**new;
	t_ennemis	*ennemis;
	int			ind;

	ind = 0;
	ennemis = ft_calloc(sizeof(t_ennemis), 1);
	if (!ennemis)
		return (0);
	while (data->list_ennemis[ind])
		ind++;
	new = ft_calloc(sizeof(t_ennemis *), ind + 2);
	if (!ennemis)
	{
		free(ennemis);
		return (0);
	}
	ft_feed_ennemis(n, ennemis, c);
	new[ind] = ennemis;
	while (--ind != -1)
		new[ind] = data->list_ennemis[ind];
	free(data->list_ennemis);
	data->list_ennemis = new;
	return (1);
}

static int	ft_create_c_e_bis(char c, t_case *caset, t_game *data, t_list *n)
{
	void	**v;
	int		*w;
	int		*h;

	v = ft_calloc(sizeof(void *), 5);
	if (!v || !ft_add_ennemis(n, data, c))
	{
		free(n->content);
		free(n);
		free(v);
		return (0);
	}
	w = &(caset->width);
	h = &(caset->height);
	v[0] = mlx_xpm_file_to_image(data->id_mlx, EFS, w, h);
	v[1] = mlx_xpm_file_to_image(data->id_mlx, EFW1, w, h);
	v[2] = mlx_xpm_file_to_image(data->id_mlx, EFS, w, h);
	v[3] = mlx_xpm_file_to_image(data->id_mlx, EFW2, w, h);
	caset->tab_img = v;
	caset->type = 'D';
	return (1);
}

int	ft_create_case_ennemis(char c, t_case *caset, t_game *data)
{
	t_list	*new;
	int		ind;

	new = ft_lstnew(caset);
	if (!new)
		return (0);
	ind = ft_ennemis_exist(c, data->list_ennemis);
	if (ind != -1)
	{
		ft_lstadd_back(&(data->list_ennemis[ind]->list_coor), new);
		return (ft_create_case(caset, *data, FLOOR, 0));
	}
	return (ft_create_c_e_bis(c, caset, data, new));
}
