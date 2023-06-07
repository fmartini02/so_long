/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:39:05 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/05 17:39:11 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	put_image(t_vars *vars)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img, vars->x, vars->y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
}

void	tex_loading(t_vars *vars)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (vars->map[i][j])
	{
		while(vars->map[i][j] != '\0' && vars->map[i][j] !='\n')
		{
			if (vars->map[i][j] == 'P')
				put_img(vars, "texture/knight_idle_anim_f0.xpm");
			else if(vars->map[i][j] == 'C')
				put_img(vars, "texture/weapon_sword_1.xpm");
			else if(vars->map[i][j] == '0')
				put_img(vars, "texture/wall_crack.xpm");
			else if(vars->map[i][j] == '1')
				put_img(vars, "texture/floor_1.xpm");
			else if(vars->map[i][j] == 'E')
				put_img(vars, "texture/slime_idle_anim_f0.xpm");
			else
				free_all();
			j++;
		}
		i++;
		j = 0;
	}
}

	
