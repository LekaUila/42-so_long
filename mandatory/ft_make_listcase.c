/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_listcase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:12:57 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/14 14:22:30 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_configurecase(char ***map_skull, t_case	*caset, t_game *data)
{
	int	b;

	b = (map_skull[caset->y][caset->x][0] == '1');
	if (b)
	{
		b += (map_skull[caset->y + 1][caset->x][0] == '1');
		b += (map_skull[caset->y - 1][caset->x][0] == '1');
		b += (map_skull[caset->y][caset->x + 1][0] == '1');
		b += (map_skull[caset->y][caset->x - 1][0] == '1');
		b += (map_skull[caset->y - 1][caset->x + 1][0] == '1');
		b += (map_skull[caset->y - 1][caset->x - 1][0] == '1');
		b += (map_skull[caset->y + 1][caset->x + 1][0] == '1');
		b += (map_skull[caset->y + 1][caset->x - 1][0] == '1');
		return (ft_check_full_w(map_skull, caset, *data, b));
	}
	return (ft_add_not_wall(map_skull[caset->y][caset->x][0], caset, data));
}

t_case	*ft_make_caset(char ***map_skull, int y, int x, t_game *data)
{
	t_case	*caset;

	caset = ft_calloc(sizeof(t_case), 1);
	if (!caset)
		return (NULL);
	caset->x = x;
	caset->y = y;
	caset->anime = 0;
	if (ft_configurecase(map_skull, caset, data))
	{
		caset->y = y + 2;
		return (caset);
	}
	free(caset);
	return (NULL);
}

t_case	**ft_make_linecase(char ***map_skull, int y, t_game *data)
{
	t_case	**linecase;
	int		x;

	x = 1;
	linecase = ft_calloc(sizeof(t_case *), ft_len_strtab(map_skull[y]) + 1);
	if (!linecase)
		return (NULL);
	linecase[0] = ft_make_caset_spe(y, 0, *data, BML);
	if (!(linecase[0]))
		return (linecase);
	while (map_skull[y][x + 1])
	{
		linecase[x] = ft_make_caset(map_skull, y, x, data);
		if (!(linecase[x]))
			return (linecase);
		x++;
	}
	linecase[x] = ft_make_caset_spe(y, x, *data, BMR);
	return (linecase);
}

t_case	***ft_make_listcase(char ***map_skull, t_game *data)
{
	t_case	***listcase;
	int		y;

	y = 1;
	listcase = ft_calloc(sizeof(t_case **), ft_len_strtabtab(map_skull) + 3);
	if (!listcase)
		return (NULL);
	listcase[0] = ft_make_toplinecase(map_skull, 0, *data);
	if (!(listcase[0]))
		return (listcase);
	listcase[1] = ft_make_toplinecase(map_skull, 1, *data);
	if (!(listcase[1]))
		return (listcase);
	listcase[2] = ft_make_toplinecase(map_skull, 2, *data);
	if (!(listcase[2]))
		return (listcase);
	while (map_skull[y + 1])
	{
		listcase[y + 2] = ft_make_linecase(map_skull, y, data);
		if (!listcase[y + 2])
			return (listcase);
		y++;
	}
	listcase[y + 2] = ft_make_bottomlinecase(map_skull, y, *data);
	return (listcase);
}
