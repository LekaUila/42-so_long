/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:52:52 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 13:40:54 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_len_line(char ***map_skull)
{
	int	i1;
	int	len;

	len = ft_len_strtab(map_skull[0]);
	i1 = 1;
	while (map_skull[i1])
	{
		if (ft_len_strtab(map_skull[i1]) != len)
		{
			ft_free_map_skull(map_skull);
			ft_error("\e[0;31mError\nInvalid Format");
		}
		i1++;
	}
	ft_putendl_fd("\e[1;32m Valid Format : ✅\e[0;m", 1);
}

int	ft_check_map_intergity(char	***map_skull)
{
	int	collectable;

	ft_putendl_fd("\e[0;35m======  START MAP VERIFICATIOM ======\n\e[0;m", 1);
	ft_putendl_fd("\n\e[1;36mFormat Verification :\e[0;m", 1);
	ft_check_len_line(map_skull);
	ft_putendl_fd("\n\e[1;36mCharacters Verification :\e[0;m", 1);
	ft_check_caractere(map_skull);
	ft_putendl_fd("\n\e[1;36mBorder Verification :\e[0;m", 1);
	ft_border_map_checker(map_skull);
	ft_putendl_fd("\n\e[1;36mFinding the way to the exit :\e[0;m", 1);
	ft_check_path_to_exit(map_skull);
	ft_putendl_fd("\n\e[1;36mFinding the way to all colectable :\e[0;m", 1);
	collectable = ft_check_path_to_collectable(map_skull);
	ft_putendl_fd("\n\e[0;35m=======  END MAP VERIFICATIOM =======\n\e[0;m", 1);
	return (collectable);
}
