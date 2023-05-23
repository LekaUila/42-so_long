/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:15:27 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/11 10:50:15 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_wrong_extensiom(char *file_name)
{
	char	*extension;

	if (ft_strlen(file_name) <= 4)
		return (1);
	extension = file_name + ft_strlen(file_name) - 4;
	return (ft_strncmp(extension, ".ber", 4));
}

int	main(int ac, char **av)
{
	t_game	data;
	char	***map_skull;

	if (ac <= 1)
		ft_error("\e[0;31mError\nNone argument");
	if (ft_wrong_extensiom(av[1]))
		ft_error("\e[0;31mError\nNeed extension : \"\e[0;33m.ber\e[0;31m\"");
	map_skull = ft_parsing(av[1]);
	data.collectable = ft_check_map_intergity(map_skull);
	data.move_count = 0;
	ft_printf("collectable : %i\n", data.collectable);
	data.id_mlx = mlx_init();
	data.window = mlx_new_window(data.id_mlx,
			ft_len_strtab(map_skull[0]) * 32 + 20,
			(ft_len_strtabtab(map_skull) + 2) * 32 + 35, "So Long");
	data.mc = NULL;
	data.listcase = ft_make_listcase(map_skull, &data);
	if (!ft_check_map_creation(data.listcase, map_skull))
		ft_close_game(&data, 1, "\e[0;31mError\nMalloc error,");
	ft_affichemap(data);
	ft_free_map_skull(map_skull);
	mlx_hook(data.window, 17, 0, ft_hook_window_destroy, &data);
	mlx_hook(data.window, 2, 1L, ft_key_hook, &data);
	mlx_loop(data.id_mlx);
}
