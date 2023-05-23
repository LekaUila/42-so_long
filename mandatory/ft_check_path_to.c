/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path_to.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:59:11 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/11 10:16:44 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_can_go_to(t_list *path, char ***map_skull, int x, int y)
{
	t_coor	*pos;
	int		b;

	b = 0;
	pos = ft_coornew(x, y);
	if (!pos)
	{
		ft_lstclear(&path, free);
		ft_free_map_skull(map_skull);
		ft_error("\e[0;31mError\nMalloc error");
	}
	b += pos->x < 0;
	b += pos->y < 0;
	b += ft_in_list(path, pos);
	b += (*(map_skull[y][x]) == '1');
	b += pos->x == ft_len_strtab(map_skull[0]);
	b += pos->y == ft_len_strtabtab(map_skull);
	free(pos);
	return (!b);
}

static int	ft_recursive_searchn(t_list *path, char ***map_skull, int x, int y)
{
	t_list	*new_case;
	t_coor	*new_coor;

	new_coor = ft_coornew(x, y);
	if (!new_coor)
	{
		ft_lstclear(&path, free);
		ft_free_map_skull(map_skull);
		ft_error("\e[0;31mError\nMalloc error");
	}
	new_case = ft_lstnew(new_coor);
	if (!new_case)
	{
		ft_lstclear(&path, free);
		ft_free_map_skull(map_skull);
		ft_error("\e[0;31mError\nMalloc error");
	}
	ft_lstadd_back(&path, new_case);
	if (ft_recursive_search(path, map_skull, NULL))
		return (1);
	return (0);
}

int	ft_recursive_search(t_list *path, char ***map_skull, t_coor *coor)
{
	t_coor			*pos;
	int				find;
	static t_coor	*coorend = NULL;

	find = 0;
	pos = ft_lstlast(path)->content;
	if (!coorend)
		coorend = coor;
	if (ft_coor_equal(coorend, pos))
	{
		ft_printf("\e[1;32m Find path to (%i;%i) : ✅\e[0;m\n", pos->x, pos->y);
		coorend = NULL;
		return (1);
	}
	else if (map_skull[pos->y][pos->x][0] == 'E')
		return (0);
	if (!find && ft_can_go_to(path, map_skull, pos->x - 1, pos->y))
		find = ft_recursive_searchn(path, map_skull, pos->x - 1, pos->y);
	if (!find && ft_can_go_to(path, map_skull, pos->x + 1, pos->y))
		find = ft_recursive_searchn(path, map_skull, pos->x + 1, pos->y);
	if (!find && ft_can_go_to(path, map_skull, pos->x, pos->y - 1))
		find = ft_recursive_searchn(path, map_skull, pos->x, pos->y - 1);
	if (!find && ft_can_go_to(path, map_skull, pos->x, pos->y + 1))
		find = ft_recursive_searchn(path, map_skull, pos->x, pos->y + 1);
	return (find);
}

t_coor	*ft_find_enter(char	***map_skull, char c)
{
	int		i1;
	int		i2;
	t_coor	*enter;

	i1 = 0;
	while (map_skull[i1])
	{
		i2 = 0;
		while (map_skull[i1][i2])
		{
			if (*(map_skull[i1][i2]) == c)
			{
				ft_printf("\e[1;32m %c at (%i;%i) \e[0;m\n", c, i2, i1);
				enter = ft_coornew(i2, i1);
				if (!enter)
					ft_free_map_skull(map_skull);
				if (!enter)
					ft_error("\e[0;31mError\nMalloc error");
				return (enter);
			}
			i2++;
		}
		i1++;
	}
	return (NULL);
}

void	ft_check_path_to_exit(char	***map_skull)
{
	t_list	*path;
	t_coor	*coor;

	ft_putendl_fd("\e[1;37m Search Enter :", 1);
	path = ft_lstnew(ft_find_enter(map_skull, 'P'));
	if (!path)
	{
		ft_free_map_skull(map_skull);
		ft_error("\e[0;31mError\nMalloc error");
	}
	ft_putendl_fd("\e[1;37m Search Exit :", 1);
	coor = ft_find_enter(map_skull, 'E');
	if (ft_recursive_search(path, map_skull, coor))
	{
		ft_print_path(path);
		ft_lstclear(&path, free);
	}
	else
	{
		free(coor);
		ft_lstclear(&path, free);
		ft_free_map_skull(map_skull);
		ft_error("\e[0;31m Error\n  can't find path to exit");
	}
	free(coor);
}
