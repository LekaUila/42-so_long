/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_cie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:33:11 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 12:52:46 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_lst_of_lst(void *lst)
{
	t_list	*list;

	list = ((t_list *)lst);
	ft_lstclear(&list, free);
}

void	ft_free_strtab(char **strtab)
{
	int	i;

	i = 0;
	while (strtab[i])
	{
		free(strtab[i]);
		i++;
	}
	free(strtab);
}

void	ft_free_map_skull(char ***map_skull)
{
	int	i;

	i = 0;
	while (map_skull[i])
	{
		ft_free_strtab(map_skull[i]);
		i++;
	}
	free(map_skull);
}

void	ft_close_game(t_game *data, int error, char *msg)
{
	ft_free_listcase(data);
	mlx_destroy_window(data->id_mlx, data->window);
	mlx_destroy_display(data->id_mlx);
	free(data->id_mlx);
	if (error)
		ft_error(msg);
	exit(EXIT_SUCCESS);
}
