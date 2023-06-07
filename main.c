/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:22:38 by fmartini          #+#    #+#             */
/*   Updated: 2023/05/31 15:25:54 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <fcntl.h>
#include "so_long.h"


int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	//void	*img;
	int		fd_map;
	t_vars	*vars;
	(void)av;
	(void)ac;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx_42");
	vars->mlx = mlx;
	vars->win = win;
//	vars.img = img;
	fd_map = open("./mappa.ber", O_RDONLY);
	vars->map = get_map(vars, fd_map);
	reset_cords(vars);
	if (valid_map(vars))
		tex_loading(vars);
	mlx_loop(mlx);
}
