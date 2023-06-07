/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:53:01 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/05 15:53:04 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	set_win_h(t_vars vars)
{
	int	i;
	
	i = 0;
	while(vars[i])
		i++;
	vars.win_h = i;
}

void	set_win_w(t_vars vars)
{
	int	i;
	
	i = 0;
	while (vars[0][i])
		i++;
	vars.win_w = i;
}

void	cord_player(t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	
	while (vars[i][j])
	{
		while(vars[i][j] != '\0' && vars[i][j] != '\n')
		{
			if(vars[i][j] == 'P')
			{
				vars.x_p = j;
				vars.y_p = i;
				return;
			}
			j++;
		}
		i++;
	}
}

void	cord_enemy(t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	
	while (vars[i][j])
	{
		while(vars[i][j] != '\0' && vars[i][j] != '\n')
		{
			if(vars[i][j] == 'E')
			{
				vars.x_e = j;
				vars.y_e = i;
				return;
			}
			j++;
		}
		i++;
	}
}

void	reset_cords(t_vars *vars)
{
	cord_player(vars);
	cord_enemy(vars);
	set_win_w(vars);
	set_win_h(vars);
}

