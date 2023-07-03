/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:51:04 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/23 18:19:44 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_movement(t_vars *vars, int keycode)
{
	if (keycode == 100)
		to_right(vars);
	else if (keycode == 115)
		to_down(vars);
	else if (keycode == 97)
		to_left(vars);
	else if (keycode == 119)
		to_up(vars);
	else
		return (0);
	return (1);
}
/*100 = d 115 = s 97 = a 119 = w*/

int	ft_move(int keycode, t_vars *vars)
{
	if (vars->map[vars->y_p][vars->x_p] == 'C')
	{
		vars->map[vars->y_p][vars->x_p] = '0';
		vars->num_c--;
	}
	if (vars->map[vars->y_p][vars->x_p] == 'E')
		ft_check_exit(vars);
	if (keycode == 119 || keycode == 65362)
		ft_movement(vars, 119);
	else if (keycode == 97 || keycode == 65361)
		ft_movement(vars, 97);
	else if (keycode == 115 || keycode == 65364)
		ft_movement(vars, 115);
	else if (keycode == 100 || keycode == 65363)
		ft_movement(vars, 100);
	else if (keycode == 65307)
		nuke_mem(vars);
	return (1);
}
/*65307=esc 65362=left 65361=down 65364=right 65363=up*/
