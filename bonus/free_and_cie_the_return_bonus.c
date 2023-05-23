/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_cie_the_return_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:33:11 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/15 13:48:01 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_case(t_case *caset, void *id_mlx)
{
	int	i;

	i = 0;
	while (caset->tab_img[i])
	{
		mlx_destroy_image(id_mlx, caset->tab_img[i]);
		i++;
	}
	free(caset->tab_img);
	free(caset);
}

void	ft_free_linecase(t_case **linecase, void *id_mlx)
{
	int	i;

	i = 0;
	while (linecase[i])
	{
		ft_free_case(linecase[i], id_mlx);
		i++;
	}
	free(linecase);
}

void	ft_free_listcase(t_game	*data)
{
	int	i;

	i = 0;
	while (data->listcase[i])
	{
		ft_free_linecase(data->listcase[i], data->id_mlx);
		i++;
	}
	free(data->listcase);
}

void	ft_do_nothing(void *useless)
{
	(void) useless;
}

void	ft_free_ennemis(t_game	*data)
{
	int	i;

	i = 0;
	while (data->list_ennemis[i])
	{
		ft_lstclear(&data->list_ennemis[i]->list_coor, ft_do_nothing);
		free(data->list_ennemis[i]);
		i++;
	}
	free(data->list_ennemis);
}
