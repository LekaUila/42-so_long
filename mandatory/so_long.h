/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:13:04 by lflandri          #+#    #+#             */
/*   Updated: 2022/11/10 16:24:39 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../LIBFT/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include "../define.d/define_border_map.h"
# include "../define.d/define_ennemis.h"
# include "../define.d/define_mc.h"
# include "../define.d/define_other.h"
# include "../define.d/define_waterfall.h"
# include "../define.d/define_waterwall.h"

typedef struct s_coor
{
	int	x;
	int	y;
}	t_coor;

t_coor	*ft_coornew(int x, int y);
int		ft_coor_equal(t_coor *c1, t_coor *c2);

typedef struct s_case
{
	int		anime;
	int		x;
	int		y;
	void	**tab_img;
	char	type;
	int		width;
	int		height;
}	t_case;

typedef struct s_game
{
	void	*id_mlx;
	void	*window;
	t_case	***listcase;
	t_case	*mc;
	int		collectable;
	int		move_count;
}	t_game;

char	***ft_parsing(char	*file);
void	ft_free_strtab(char **strtab);
void	ft_free_map_skull(char ***map_skull);
void	ft_free_lst_of_lst(void *lst);
void	ft_close_game(t_game *data, int error, char *msg);
int		ft_check_map_intergity(char	***map_skull);
void	ft_check_caractere(char ***map_skull);
void	ft_border_map_checker(char ***map_skull);
void	ft_check_path_to_exit(char	***map_skull);
int		ft_len_strtabtab(char ***strtabtab);
int		ft_in_list(t_list *path, t_coor *pos);
void	ft_print_path(t_list *path);
int		ft_check_path_to_collectable(char	***map_skull);
t_coor	*ft_find_enter(char	***map_skull, char c);
int		ft_recursive_search(t_list *path, char ***map_skull, t_coor *coor);

t_case	***ft_make_listcase(char ***map_skull, t_game *data);

void	ft_affichemap(t_game data);

int		ft_check_full_w(char ***map_sku, t_case	*caset, t_game data, int w);
int		ft_check_r_c_w(char ***map_sku, t_case *caset, t_game data, int water);
int		ft_check_b_w(char ***map_sku, t_case *caset, t_game data, int water);
int		ft_check_c_w(char ***map_sku, t_case *caset, t_game data, int water);
int		ft_create_simple_wall(t_case *caset, t_game data);

t_case	*ft_make_caset_spe(int y, int x, t_game data, char *file);
t_case	**ft_make_bottomlinecase(char ***map_skull, int y, t_game data);
t_case	**ft_make_toplinecase(char ***map_skull, int y, t_game data);

int		ft_iswaterfall(char ***map_skull, int x);
t_case	*ft_create_water_fall(char ***map_skull, int y, int x, t_game data);

int		ft_add_not_wall(char c, t_case *caset, t_game *data);

int		ft_key_hook(int keycode, void *param);
int		ft_hook_window_destroy(void	*param);

void	ft_mc_move(t_game *data, int x, int y, char	*img);

int		ft_check_map_creation(t_case ***listcase, char ***map_skull);

void	ft_free_listcase(t_game	*data);

#endif