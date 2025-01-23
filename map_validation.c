/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:55:05 by francema          #+#    #+#             */
/*   Updated: 2025/01/22 18:32:56 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_border(t_vars *vars)
{
	check_vertical(vars);
	check_orizontal(vars);
	check_vertical_2(vars);
	check_orizontal_2(vars);
	return (1);
}

int	elem_counting(t_vars *vars)
{
	int	y;
	int	x;

	x = 0;
	y = vars->win_h - 1;
	while (y >= 0)
	{
		while (vars->map[y][x] != '\0' && vars->map[y][x] != '\n')
		{
			if (vars->map[y][x] == 'C')
				vars->num_c++;
			else if (vars->map[y][x] == 'P')
				vars->num_p++;
			else if (vars->map[y][x] == 'E')
				vars->num_e++;
			else if (!(vars->map[y][x] == '1' || vars->map[y][x] == '0'))
				ft_nuke_first_mem(vars);
			x++;
		}
		y--;
		x = 0;
	}
	ft_check_num_elm(vars);
	return (1);
}

void	flood_fill(char **tab, t_point s, t_point b)
{
	if (b.y < 0 || b.x < 0
		|| b.x >= s.x || b.y >= s.y
		|| (tab[b.y][b.x] == '1' ))
		return ;
	if (tab[b.y][b.x] == 'E')
	{
		tab[b.y][b.x] = '1';
		return ;
	}
	tab[b.y][b.x] = '1';
	flood_fill(tab, s, (t_point){b.x - 1, b.y});
	flood_fill(tab, s, (t_point){b.x + 1, b.y});
	flood_fill(tab, s, (t_point){b.x, b.y - 1});
	flood_fill(tab, s, (t_point){b.x, b.y + 1});
}

void	ft_flood_test(t_vars *vars)
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

int	valid_map(t_vars *vars)
{
	vars->num_c = 0;
	vars->num_p = 0;
	vars->num_e = 0;
	if (check_border(vars) && elem_counting(vars))
		return (1);
	else
		ft_nuke_first_mem(vars);
	return (0);
}
