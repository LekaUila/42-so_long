/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_border_map_checker_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:51:17 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/11 14:16:39 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_check_top_border(char ***map_skull)
{
	int	i;

	i = 0;
	while (map_skull[0][i])
	{
		if (*(map_skull[0][i++]) != '1')
		{
			ft_putendl_fd("\e[0;31m Top Border    : ❌\e[0;m", 1);
			return (0);
		}
	}
	ft_putendl_fd("\e[1;32m Top Border    : ✅\e[0;m", 1);
	return (1);
}

static int	ft_check_bottom_border(char ***map_skull)
{
	int	i;
	int	len;

	i = 0;
	len = ft_len_strtabtab(map_skull);
	while (map_skull[len - 1][i])
	{
		if (*(map_skull[len - 1][i++]) != '1')
		{
			ft_putendl_fd("\e[0;31m Bottom Border : ❌\e[0;m", 1);
			return (0);
		}
	}
	ft_putendl_fd("\e[1;32m Bottom Border : ✅\e[0;m", 1);
	return (1);
}

static int	ft_check_left_border(char ***map_skull)
{
	int	i;

	i = 0;
	while (map_skull[i])
	{
		if (*(map_skull[i++][0]) != '1')
		{
			ft_putendl_fd("\e[0;31m Left Border   : ❌\e[0;m", 1);
			return (0);
		}
	}
	ft_putendl_fd("\e[1;32m Left Border   : ✅\e[0;m", 1);
	return (1);
}

static int	ft_check_right_border(char ***map_skull)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (map_skull[0][len])
		len++;
	while (map_skull[i])
	{
		if (*(map_skull[i++][len - 1]) != '1')
		{
			ft_putendl_fd("\e[0;31m Right Border   : ❌\e[0;m", 1);
			return (0);
		}
	}
	ft_putendl_fd("\e[1;32m Right Border  : ✅\e[0;m", 1);
	return (1);
}

void	ft_border_map_checker(char ***map_skull)
{
	int	b;

	b = 1;
	if (!ft_check_top_border(map_skull))
		b = 0;
	if (!ft_check_left_border(map_skull))
		b = 0;
	if (!ft_check_right_border(map_skull))
		b = 0;
	if (!ft_check_bottom_border(map_skull))
		b = 0;
	if (b)
		return ;
	ft_free_map_skull(map_skull);
	ft_error("\e[0;31mError\nIncorrect Border");
}
