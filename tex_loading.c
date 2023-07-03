/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:39:05 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/23 16:28:29 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	tex_loading(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	ft_put_tex(vars);
	while (y < vars->win_h)
	{
		while (vars->map[y][x] != '\0' && vars->map[y][x] != '\n')
		{
			if (vars->map[y][x] == 'P')
				ft_put_pla(vars, y, x);
			else if (vars->map[y][x] == 'C')
				ft_put_coll(vars, y, x);
			else if (vars->map[y][x] == 'N')
				ft_put_ene(vars, y, x);
			x++;
		}
		y++;
		x = 0;
	}
	tex_loading_else(vars);
}

void	tex_loading_else(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < vars->win_h)
	{
		while (vars->map[y][x] != '\0' && vars->map[y][x] != '\n')
		{
			if (vars->map[y][x] == 'E')
				ft_put_exit(vars, y, x);
			else if (vars->map[y][x] == '1')
				ft_put_wall(vars, y, x);
			else if (vars->map[y][x] == '0')
				ft_put_flo(vars, y, x);
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_put_pla(t_vars *vars, int y, int x)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->pla, x * 16, y * 16);
}

void	ft_put_flo(t_vars *vars, int y, int x)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->flo, x * 16, y * 16);
}
