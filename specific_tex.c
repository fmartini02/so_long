/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_tex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:39:48 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/27 17:14:07 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

void	ft_put_tex(t_vars *vars)
{
	int	w;
	int	h;

	vars->flo = mlx_xpm_file_to_image(vars->mlx,
			"textures/floor_1.xpm", &w, &h);
	vars->pla = mlx_xpm_file_to_image(vars->mlx,
			"textures/knight_idle_anim_f0.xpm", &w, &h);
	vars->wall = mlx_xpm_file_to_image(vars->mlx,
			"textures/wall_crack.xpm", &w, &h);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, 
			"textures/chest_closed_anim_f0.xpm", &w, &h);
	vars->ene = mlx_xpm_file_to_image(vars->mlx,
			"textures/slime_idle_anim_f0.xpm", &w, &h);
	vars->coll = mlx_xpm_file_to_image(vars->mlx,
			"textures/weapon_sword_1.xpm", &w, &h);
}

void	ft_put_wall(t_vars *vars, int y, int x)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, x * 16, y * 16);
}

void	ft_put_exit(t_vars *vars, int y, int x)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, x * 16, y * 16);
}

void	ft_put_ene(t_vars *vars, int y, int x)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->ene, x * 16, y * 16);
}

void	ft_put_coll(t_vars *vars, int y, int x)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->coll, x * 16, y * 16);
}
