/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:55:50 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/27 18:03:42 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_vertical(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->win_h)
	{
		if (vars->map[i][0] != '\n')
		{
			if (vars->map[i][0] != '1')
			{
				ft_nuke_first_mem(vars);
			}
			i++;
		}
		else if (vars->map[i][0] == '\n')
			ft_nuke_first_mem(vars);
	}
}

void	check_orizontal(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->win_w)
	{
		if (vars->map[0][i] != '\n')
		{
			if (vars->map[0][i] != '1')
			{
				ft_nuke_first_mem(vars);
			}
			i++;
		}
		else if (vars->map[i][0] == '\n')
			ft_nuke_first_mem(vars);
	}
}

void	check_vertical_2(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->win_w)
	{
		if (vars->map[vars->win_h - 1][i] != '\n')
		{
			if (vars->map[vars->win_h -1][i] != '1')
			{
				ft_nuke_first_mem(vars);
			}
			i++;
		}
		else if (vars->map[i][0] == '\n')
			ft_nuke_first_mem(vars);
	}
}

void	check_orizontal_2(t_vars *vars)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(vars->map[0]);
	while (i < vars->win_h)
	{
		if (vars->map[i][vars->win_w - 1] != '\n' )
		{
			if (vars->map[i][vars->win_w - 1] != '1' || l != vars->win_w)
				ft_nuke_first_mem(vars);
			i++;
			if (i < vars->win_h)
				l = ft_strlen(vars->map[i]);
		}
		else if (vars->map[i][0] == '\n')
			ft_nuke_first_mem(vars);
	}
}
