/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:22:38 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/29 18:30:00 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <fcntl.h>
#include "so_long.h"

void	ft_mlx_initer(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (vars->win_w * 16), 
			(vars->win_h * 16), "mlx_42");
	mlx_hook(vars->win, 2, 1L << 0, ft_move, vars);
	mlx_hook(vars->win, 17, 0, nuke_mem, vars);
}

int	main(int ac, char **av)
{
	int		fd_map;
	t_vars	*vars;

	if (ac == 2)
	{
		vars = malloc(sizeof(t_vars));
		fd_map = ft_check_path(av[1], vars);
		get_map(vars, fd_map);
		reset_cords(vars);
		vars->moves = 0;
		if (valid_map(vars))
		{
			ft_check_stronzi(vars);
			ft_mlx_initer(vars);
			reset_cords(vars);
			tex_loading(vars);
		}
		else
			nuke_mem(vars);
		mlx_loop(vars->mlx);
	}
	else
		ft_printf("\nsei un cretino\n\n");
}
