/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:27:42 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/29 18:24:48 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_num_elm(t_vars *vars)
{
	if (vars->num_c == 0 
		|| vars->num_p == 0 
		|| vars->num_e == 0 
		|| vars->num_p > 1
		|| vars->num_e > 1)
		ft_nuke_first_mem(vars);
}

int	valid_map(t_vars *vars)
{
	vars->num_c = 0;
	vars->num_p = 0;
	vars->num_e = 0;
	if (check_border(vars) && check_elm(vars))
		return (1);
	else
		ft_nuke_first_mem(vars);
	return (0);
}

void	ft_check_stronzi(t_vars *vars)
{
	t_point	cords;
	t_point	size;

	size = (t_point){vars->win_w, vars->win_h};
	cords = (t_point){vars->x_p, vars->y_p};
	vars->temp[cords.y][cords.x] = '0';
	flood_fill(vars->temp, size, cords);
	size.y -= 1;
	size.x -= 1;
	while (size.y >= 0)
	{
		while (size.x > 0)
		{
			if (vars->temp[size.y][size.x] != '1' &&
					vars->temp[size.y][size.x] != '0')
				ft_nuke_first_mem(vars);
			size.x--;
		}
		size.x = vars->win_w - 1;
		size.y--;
	}
}
