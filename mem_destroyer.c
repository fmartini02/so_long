/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_destroyer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:13:53 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/29 19:33:33 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_str_map(t_vars *vars)
{
	char	**map;
	char	**temp;
	int		y;

	y = 0;
	map = vars->map;
	temp = vars->temp;
	while (vars->map[y])
	{
		free(vars->map[y]);
		free(vars->temp[y]);
		vars->map[y] = NULL;
		vars->temp[y] = NULL;
		y++;
	}
	free(map);
	free(temp);
	vars->temp = NULL;
	vars->map = NULL;
	ft_printf("\nmatrix freed\n");
}

void	ft_destroy_tex(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->pla);
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->ene);
	mlx_destroy_image(vars->mlx, vars->coll);
	mlx_destroy_image(vars->mlx, vars->flo);
	mlx_destroy_image(vars->mlx, vars->exit);
	ft_printf("textures freed");
}

void	ft_nuke_first_mem(t_vars *vars)
{
	ft_printf("Error:\nshitty map");
	ft_free_str_map(vars);
	free(vars);
	vars = NULL;
	exit(0);
}

int	nuke_mem(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_destroy_tex(vars);
	mlx_destroy_display(vars->mlx);
	ft_free_str_map(vars);
	free(vars-> mlx);
	free(vars);
	vars = NULL;
	ft_printf("mlx freed\n");
	exit(0);
	return (0);
}

void	ft_free_init(t_vars *vars, char *s)
{
	ft_printf("Error\nMap is not valid\n");
	free(s);
	free(vars);
	exit(0);
}
