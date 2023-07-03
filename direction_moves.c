/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:23:31 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/26 17:22:34 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	to_up(t_vars *vars)
{
	if (vars->map[vars->y_p - 1][vars->x_p] == '1' 
			|| (vars->map[vars->y_p - 1][vars->x_p] == 'E' 
			&& vars->num_c != 0))
		return ;
	else
	{
		ft_put_flo(vars, vars->y_p, vars->x_p);
		vars->y_p--;
		ft_printf("move:%d\n", vars->moves++);
		ft_put_pla(vars, vars->y_p, vars->x_p);
	}
}

void	to_down(t_vars *vars)
{
	if (vars->map[vars->y_p + 1][vars->x_p] == '1' 
			|| (vars->map[vars->y_p + 1][vars->x_p] == 'E' 
			&& vars->num_c != 0))
		return ;
	else
	{
		ft_put_flo(vars, vars->y_p, vars->x_p);
		vars->y_p++;
		ft_printf("move:%d\n", vars->moves++);
		ft_put_pla(vars, vars->y_p, vars->x_p);
	}
}

void	to_left(t_vars *vars)
{
	if (vars->map[vars->y_p][vars->x_p - 1] == '1' 
			|| (vars->map[vars->y_p][vars->x_p - 1] == 'E' 
			&& vars->num_c != 0))
		return ;
	else
	{
		ft_put_flo(vars, vars->y_p, vars->x_p);
		vars->x_p--;
		ft_printf("move:%d\n", vars->moves++);
		ft_put_pla(vars, vars->y_p, vars->x_p);
	}
}

void	to_right(t_vars *vars)
{
	if (vars->map[vars->y_p][vars->x_p + 1] == '1' 
			|| (vars->map[vars->y_p][vars->x_p + 1] == 'E' 
			&& vars->num_c != 0))
		return ;
	else
	{
		ft_put_flo(vars, vars->y_p, vars->x_p);
		vars->x_p++;
		ft_printf("move:%d\n", vars->moves++);
		ft_put_pla(vars, vars->y_p, vars->x_p);
	}
}
