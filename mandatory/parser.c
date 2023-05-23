/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:21:07 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 13:45:36 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_print_map_skull(char ***map_skull)
{
	int	i1;
	int	i2;

	i1 = 0;
	ft_putendl_fd("\e[1;36mThis is your map :\n\e[0;33m", 1);
	while (map_skull[i1])
	{
		i2 = 0;
		while (map_skull[i1][i2])
		{
			ft_putstr_fd(map_skull[i1][i2], 1);
			i2++;
		}
		ft_putchar_fd('\n', 1);
		i1++;
	}
	ft_putstr_fd("\e[0;m\n", 1);
}

static char	**ft_sep_line_in_char(char *line)
{
	char	**strtab;
	char	*str;
	int		i;

	i = 0;
	strtab = ft_calloc(sizeof(char *), ft_strlen(line) + 1);
	if (!strtab)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		str = ft_calloc(1, 2);
		if (!str)
		{
			ft_free_strtab(strtab);
			return (NULL);
		}
		*str = line[i];
		strtab[i] = str;
		i++;
	}
	return (strtab);
}

static char	***ft_addstrtab_to_strtabtab(char ***map_skull, char **strtab)
{
	char	***map_skull_new;
	int		i;

	i = 0;
	while (map_skull[i])
		i++;
	map_skull_new = ft_calloc(sizeof(char ***), i + 2);
	if (!map_skull_new)
	{
		ft_free_map_skull(map_skull);
		ft_free_strtab(strtab);
		ft_error("\e[0;31mError\nMalloc error");
	}
	map_skull_new[i] = strtab;
	while (i > 0)
	{
		map_skull_new[i - 1] = map_skull[i - 1];
		i --;
	}
	free(map_skull);
	return (map_skull_new);
}

static char	***ft_read_map(int fd)
{
	char	***map_skull;
	char	**map_line;
	char	*line;

	map_skull = ft_calloc(sizeof(char ***), 1);
	if (!map_skull)
		ft_error("\e[0;31mError\nMalloc error");
	line = "lol";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			map_line = ft_sep_line_in_char(line);
			free(line);
			if (!map_line)
			{
				ft_free_map_skull(map_skull);
				ft_error("\e[0;31mError\nMalloc error");
			}
			map_skull = ft_addstrtab_to_strtabtab(map_skull, map_line);
		}
	}
	return (map_skull);
}

char	***ft_parsing(char	*file)
{
	int		fd;
	char	***map_skull;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("\e[0;31mError\nFile can't be opened");
	map_skull = ft_read_map(fd);
	if (!(*map_skull))
	{
		free(map_skull);
		ft_error("\e[0;31mError\nEmpty map");
	}
	ft_print_map_skull(map_skull);
	return (map_skull);
}
