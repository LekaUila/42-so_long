/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:21:06 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/15 14:26:20 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_win(t_game *data)
{
	ft_printf("\e[1;32mYOU WIN !\e[0;m\n");
	ft_printf("\e[1;32mYOU WIN !\e[0;m\n");
	ft_printf("\e[1;32mYOU WIN !\e[0;m\n");
	ft_close_game(data, 0, NULL);
}

void	ft_lose(t_game *data)
{
	ft_printf("\e[0;31mYOU LOSE !\e[0;m\n");
	ft_printf("\e[0;31mYOU LOSE !\e[0;m\n");
	ft_printf("\e[0;31mYOU LOSE !\e[0;m\n");
	ft_close_game(data, 0, NULL);
}
