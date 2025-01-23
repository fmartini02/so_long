/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:53:01 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/23 16:28:46 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_win_h(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
		i++;
	vars->win_h = i ;
}

void	set_win_w(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[0][i])
		i++;
	vars->win_w = i;
}

void	cord_player(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->win_h)
	{
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == 'P')
			{
				vars->x_p = j;
				vars->y_p = i;
				return ;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	cord_enemy(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->win_h)
	{
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == 'E')
			{
				vars->x_e = j;
				vars->y_e = i;
				return ;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	reset_cords(t_vars *vars)
{
	set_win_w(vars);
	set_win_h(vars);
	cord_player(vars);
	cord_enemy(vars);
}
