/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_creation_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:37:43 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/11 14:16:26 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_line_creation(t_case **linecase, char ***map_skull)
{
	int	len;
	int	i;

	len = ft_len_strtab(map_skull[0]);
	i = 0;
	while (i != len)
	{
		if (!linecase[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_map_creation(t_case ***listcase, char ***map_skull)
{
	int	len;
	int	i;

	len = ft_len_strtabtab(map_skull) + 2;
	i = 0;
	while (i != len)
	{
		if (listcase[i])
		{
			if (!ft_check_line_creation(listcase[i], map_skull))
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}
