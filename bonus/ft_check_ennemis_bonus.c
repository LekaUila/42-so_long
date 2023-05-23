/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ennemis_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:53:22 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/15 14:19:08 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_others_ennemis(char ***map_skull, int i2, int i1)
{
	int	b;

	b = !ft_strchr("01", *(map_skull[i1 + 1][i2]));
	b += !ft_strchr("01", *(map_skull[i1 - 1][i2]));
	b += !ft_strchr("01", *(map_skull[i1][i2 + 1]));
	b += !ft_strchr("01", *(map_skull[i1][i2 - 1]));
	return (b);
}

static int	ft_ennemis_check(char ***map_skull, char c)
{
	int	i1;
	int	i2;
	int	count;

	count = 0;
	i1 = 0;
	while (map_skull[i1])
	{
		i2 = 0;
		while (map_skull[i1][i2])
		{
			if (*(map_skull[i1][i2]) == c)
			{
				count++;
			}
			i2++;
		}
		i1++;
	}
	return (count >= 2);
}

int	ft_check_ennemis(char ***map_skull)
{
	int		i1;
	int		i2;
	char	*bad;

	bad = "\e[0;31m Invalid Ennemis Definition in map : ❌\e[0;m";
	i1 = -1;
	while (map_skull[++i1])
	{
		i2 = 0;
		while (map_skull[i1][i2])
		{
			if (!ft_strchr("01CPE", *(map_skull[i1][i2])))
			{
				if (!ft_ennemis_check(map_skull, *(map_skull[i1][i2]))
					|| ft_others_ennemis(map_skull, i2, i1))
				{
					ft_putendl_fd(bad, 1);
					return (0);
				}
			}
			i2++;
		}
	}
	ft_putendl_fd("\e[1;32m Valid Ennemis Definition in map : ✅\e[0;m", 1);
	return (1);
}
