/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ennemis_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:52:31 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/15 14:27:22 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_ennemis_move(t_game *data)
{
	int			ind;
	t_ennemis	*enmis;
	t_case		*caset[2];

	if (((data->move_count + 1) % 3))
		return ;
	ind = 0;
	while (data->list_ennemis[ind])
	{
		enmis = data->list_ennemis[ind++];
		caset[0] = ft_lstget_elt(enmis->elt, enmis->list_coor)->content;
		if (ft_lstget_elt(enmis->elt + 1, enmis->list_coor) == 0)
		{
			caset[1] = enmis->list_coor->content;
			enmis->elt = 0;
		}
		else
		{
			caset[1] = ft_lstget_elt(enmis->elt + 1, enmis->list_coor)->content;
			enmis->elt++;
		}
		if (caset[1]->type == 'P')
			ft_lose(data);
		ft_swap_case(caset[0], caset[1]);
	}
}
