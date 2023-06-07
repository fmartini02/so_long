/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:11:02 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/01 17:15:36 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_vars {
	void	*mlx;
	void	*img;
	void	*win;
	int		win_w;
	int		win_h;
	int		x_p;
	int		y_p;
	int		movement;
	char	**map;
	int		x_e;
	int		y_e;
	//int		sign;
	int		x;
	int		num_c;
	int		num_p;
	int		num_e;
	int		y;	
}	t_vars;

char	**get_map(t_vars *vars, int fd_map);
int		main();
int		*chek_elm(t_vars *vars);
int		check_border(t_vars *vars);
void	reset_cords(t_vars *map);
int		*valid_map(t_vars *vars);
void	tex_loading(t_vars *vars);
void	put_image(t_vars *vars);
void	cord_player(char **map);
void	cord_enemy(char **map);
void	set_win_w(char **map);
void	set_win_h(char **map);

#endif
