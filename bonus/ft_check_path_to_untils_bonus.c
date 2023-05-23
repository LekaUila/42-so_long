/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path_to_untils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:59:11 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/11 14:16:20 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_in_list(t_list *path, t_coor *pos)
{
	while (path)
	{
		if (ft_coor_equal(path->content, pos))
			return (1);
		path = path->next;
	}
	return (0);
}

void	ft_print_path(t_list *path)
{
	t_coor	*coor;

	ft_putendl_fd("\e[1;37m Path :", 1);
	ft_putstr_fd("\e[1;34m", 1);
	while (path)
	{
		coor = ((t_coor *)(path->content));
		ft_printf("(%i;%i)", coor->x, coor->y);
		if (path->next)
			ft_putstr_fd(" -> ", 1);
		path = path->next;
	}
	ft_putstr_fd("\n\e[0;m", 1);
}

void	ft_find_all_collectable(char	***map_skull, t_list **collectable)
{
	int		i1;
	int		i2;
	t_list	*tempo;

	i1 = -1;
	while (map_skull[++i1])
	{
		i2 = -1;
		while (map_skull[i1][++i2])
		{
			if (*(map_skull[i1][i2]) == 'C')
			{
				ft_printf("\e[1;32m C at (%i;%i) \e[0;m\n", i2, i1);
				tempo = ft_lstnew(ft_lstnew(ft_coornew(i2, i1)));
				if (!tempo || !(tempo->content)
					|| !(((t_list *)tempo->content))->content)
				{
					ft_lstclear(collectable, free);
					*collectable = NULL;
					return ;
				}
				ft_lstadd_back(collectable, tempo);
			}
		}
	}
}

static int	ft_check_all(char ***map_skull, t_list	**list, t_coor	*enter)
{
	t_list	*casev;
	t_coor	*coor;
	int		ret;

	casev = *list;
	ret = 0;
	while (casev)
	{
		coor = ((t_coor *)((t_list *)casev->content)->content);
		ft_printf("\e[1;37m C (%i;%i) Checking\n\e[0;m", coor->x, coor->y);
		if (ft_recursive_search(casev->content, map_skull, enter))
		{
			ft_print_path(casev->content);
		}
		else
		{
			free(enter);
			ft_free_map_skull(map_skull);
			ft_lstclear(list, ft_free_lst_of_lst);
			ft_error("\e[0;31m Error\n  can't find path to enter (P)");
		}
		casev = casev->next;
		ret++;
	}
	return (ret);
}

int	ft_check_path_to_collectable(char ***map_skull)
{
	t_coor	*enter;
	t_list	**collectable;
	t_list	*not_used;
	int		ret;

	not_used = NULL;
	collectable = &not_used;
	ft_putendl_fd("\e[1;37m Search Enter :", 1);
	enter = ft_find_enter(map_skull, 'P');
	ft_putendl_fd("\e[1;37m Search All collectable :", 1);
	ft_find_all_collectable(map_skull, collectable);
	if (!enter || !collectable)
	{
		free(enter);
		ft_free_map_skull(map_skull);
		ft_lstclear(collectable, ft_free_lst_of_lst);
		ft_error("\e[0;31mError\nMalloc error");
	}
	ret = ft_check_all(map_skull, collectable, enter);
	free(enter);
	ft_lstclear(collectable, ft_free_lst_of_lst);
	return (ret);
}
