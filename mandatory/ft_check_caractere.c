/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_caractere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:46:39 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 12:59:15 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_msg_c_is_in_map(char c, int check)
{
	if (check == 1)
	{
		ft_putstr_fd("\e[1;32m Character ", 1);
		ft_putchar_fd(c, 1);
		ft_putendl_fd(" in map     : ✅\e[0;m", 1);
		return ;
	}
	ft_putstr_fd("\e[0;31m Character ", 1);
	ft_putchar_fd(c, 1);
	ft_putendl_fd(" in map     : ❌", 1);
	if (!check)
		ft_putendl_fd("     No Character Detected\e[0;m", 1);
	else
		ft_putendl_fd("     Two or more Character Detected\e[0;m", 1);
}

static int	ft_c_is_in_map(char c, char ***map_skull)
{
	int	i1;
	int	i2;
	int	check;

	check = 0;
	i1 = 0;
	while (map_skull[i1])
	{
		i2 = 0;
		while (map_skull[i1][i2])
		{
			if (*(map_skull[i1][i2]) == c)
			{
				check++;
			}
			i2++;
		}
		i1++;
	}
	ft_msg_c_is_in_map(c, check);
	return (check == 1);
}

static int	ft_collec_is_in_map(char ***map_skull)
{
	int	i1;
	int	i2;

	i1 = 0;
	while (map_skull[i1])
	{
		i2 = 0;
		while (map_skull[i1][i2])
		{
			if (*(map_skull[i1][i2]) == 'C')
			{
				ft_putendl_fd("\e[1;32m Character C in map     : ✅\e[0;m", 1);
				return (1);
			}
			i2++;
		}
		i1++;
	}
	ft_putendl_fd("\e[0;31m Character C in map     : ❌\e[0;m", 1);
	return (0);
}

static int	ft_charmap_correct(char ***map_skull)
{
	int	i1;
	int	i2;

	i1 = 0;
	while (map_skull[i1])
	{
		i2 = 0;
		while (map_skull[i1][i2])
		{
			if (!ft_strchr("01CPE", *(map_skull[i1][i2])))
			{
				ft_putendl_fd("\e[0;31m Valid character in map : ❌\e[0;m", 1);
				return (0);
			}
			i2++;
		}
		i1++;
	}
	ft_putendl_fd("\e[1;32m Valid character in map : ✅\e[0;m", 1);
	return (1);
}

void	ft_check_caractere(char ***map_skull)
{
	int	b;

	b = 1;
	if (!ft_collec_is_in_map(map_skull))
		b = 0;
	if (!ft_c_is_in_map('P', map_skull))
		b = 0;
	if (!ft_c_is_in_map('E', map_skull))
		b = 0;
	if (!ft_charmap_correct(map_skull))
		b = 0;
	if (b)
		return ;
	ft_free_map_skull(map_skull);
	ft_error("\e[0;31mError\nCharacters Error");
}
