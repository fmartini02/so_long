/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:22:38 by fmartini          #+#    #+#             */
/*   Updated: 2025/01/22 18:41:27 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "so_long.h"
#include "minilibx-linux/mlx.h"

void	mapps(t_vars *vars, int fd_map)
{
	get_map(vars, fd_map);
	reset_cords(vars);
	vars->moves = 0;
	if (valid_map(vars))
	{
		ft_flood_test(vars);
		ft_mlx_initer(vars);
		reset_cords(vars);
		tex_loading(vars);
	}
	else
		nuke_mem(vars);
}

int	main(int ac, char **av)
{
	int		fd_map;
	t_vars	*vars;

	if (ac == 2)
	{
		vars = malloc(sizeof(t_vars));
		if (!vars)
			return (0);
		fd_map = ft_check_path(av[1], vars);
		mapps(vars, fd_map);
		mlx_loop(vars->mlx);
	}
	else if(ac <= 1)
		ft_printf("\nTHE MAP FOOL\n\n");
	else
		ft_printf("\nTOO MANY ARGUMENTS\n\n");
}
