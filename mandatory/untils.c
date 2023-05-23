/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:14:08 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/09 12:53:28 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len_strtabtab(char ***strtabtab)
{
	int	len;

	len = 0;
	while (strtabtab[len])
		len++;
	return (len);
}
