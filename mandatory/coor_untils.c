/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coor_untils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:13:30 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 12:48:59 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_coor_equal(t_coor *c1, t_coor *c2)
{
	int	b1;
	int	b2;

	b1 = c1->x == c2->x;
	b2 = c1->y == c2->y;
	return (b1 && b2);
}

t_coor	*ft_coornew(int x, int y)
{
	t_coor	*coor;

	coor = malloc(sizeof(t_coor));
	if (coor)
	{
		coor->x = x;
		coor->y = y;
	}
	return (coor);
}
