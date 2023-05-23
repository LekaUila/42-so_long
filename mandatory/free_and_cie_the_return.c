/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_cie_the_return.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:33:11 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 12:53:14 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
