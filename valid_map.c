/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:27:42 by fmartini          #+#    #+#             */
/*   Updated: 2023/05/31 17:27:46 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	*chek_elm(t_vars *vars)
{
	vars->c = 0;
	vars->p = 0;
	vars->e = 0;
	int	y;
	y = vars->win_h - 1;	
	while(vars->map[i][y])
	{
		x = 0;
		while(vars->map[vars->y][vars->x] != '\0')
		{
			if(vars.map[vars->y][vars->x] == 'C')
				vars->num_c++;
			else if(vars->map[vars->y][vars->x] == 'P')
				vars.num_p++;
			else if(vars->map[vars->y][vars->x] == 'E')
				vars->num_e++;
			x++;
		}
	}
	if(vars->num_c == 0 || vars->num_p == 0 || vars->num_e == 0 || vars->num_p > 1)
			ft_error(vars, ft_map_err(vars->map));
	return(1);
}

int	check_border(t_vars *vars)
{
	int 	i;

	i = 0;
	while(i <= vars->win_h)
	{
		if(vars->map[i++][0] != '1')
			return (0);
	}
	i =  0;
	while(i <= vars->win_w)
	{
		if(vars->map[0][i++] != '1')
			return (0);
	}
	i =  0;
	while(i <= win_w)
	{
		if(vars->map[var->win_h][i++] != '1')
			return (0);
	}
	i =  0;
	while(i <= win_h)
	{
		if(vars->map[i++][var->win_w] != '1')
			return (0);
	}
	return(1)
}

int	*valid_map(t_vars *vars)
{
	if(vars->win_h != vars->win_w && 
			check_border(vars) && check_elm(vars))
			return(1);
	/*else
		ft_free_all();*/
}
