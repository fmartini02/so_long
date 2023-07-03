/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:11:02 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/27 16:59:43 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_vars {
	void	*mlx;
	void	*pla;
	void	*flo;
	void	*exit;
	void	*wall;
	void	*ene;
	void	*coll;
	void	*win;
	int		win_w;
	int		win_h;
	int		x_p;
	int		y_p;
	int		moves;
	char	**map;
	char	**temp;
	int		x_e;
	int		y_e;
	int		num_c;
	int		num_p;
	int		num_e;
	int		num_n;
	char	*path;	
}	t_vars;

void	get_map(t_vars *vars, int fd_map);
int		main(int ac, char **av);
void	ft_free_str_map(t_vars *vars);
void	to_right(t_vars *vars);
void	to_left(t_vars *vars);
void	to_down(t_vars *vars);
void	to_up(t_vars *vars);
int		ft_move(int keycode, t_vars *vars);
int		check_elm(t_vars *vars);
int		check_border(t_vars *vars);
void	reset_cords(t_vars *map);
int		valid_map(t_vars *vars);
void	tex_loading(t_vars *vars);
void	cord_player(t_vars *vars);
void	cord_enemy(t_vars *vars);
void	set_win_w(t_vars *vars);
void	set_win_h(t_vars *vars);
void	ft_check_exit(t_vars *vars);
int		ft_movement(t_vars *vars, int keycode);
void	check_vertical(t_vars *vars);
void	check_orizontal(t_vars *vars);
void	check_vertical_2(t_vars *vars);
void	check_orizontal_2(t_vars *vars);
int		nuke_mem(t_vars *vars);
void	ft_check_num_elm(t_vars *vars);
void	tex_loading_else(t_vars *vars);
void	ft_put_coll(t_vars *vars, int y, int x);
void	ft_put_ene(t_vars *vars, int y, int x);
void	ft_put_exit(t_vars *vars, int y, int x);
void	ft_put_wall(t_vars *vars, int y, int x);
void	ft_put_flo(t_vars *vars, int y, int x);
void	ft_put_pla(t_vars *vars, int y, int x);
void	ft_put_tex(t_vars *vars);
void	ft_check_stronzi(t_vars *vars);
void	ft_nuke_first_mem(t_vars *vars);
void	ft_check_file_map(t_vars *vars);
void	ft_mlx_initer(t_vars *vars);
void	flood_fill(char **tab, t_point s, t_point b);
int		ft_check_path(char *p, t_vars *vars);
int		ft_check_nwline(char *s);
void	ft_free_init(t_vars *vars, char *s);

#endif
