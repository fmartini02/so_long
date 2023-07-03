/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:38:14 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/30 15:49:01 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_path(char *p, t_vars *vars)
{
	int		fd;
	char	*path;

	path = ft_strjoin("./maps/", p);
	if (!(ft_strstr(path, ".ber")))
	{
		ft_printf("Error:\nmap not .ber!\n");
		free(vars);
		exit(0);
	}
	fd = open(path, O_RDONLY);
	free(path);
	if (fd < 0)
	{
		ft_printf("File not found!\n");
		free(vars);
		exit(0);
	}
	return (fd);
}

void	ft_check_file_map(t_vars *vars)
{
	char	*t;

	t = vars->map[0];
	if (!t)
	{
		ft_free_str_map(vars);
		free(vars);
		ft_printf("empty mapp\n");
		exit(0);
	}
	else if (t[0] != '1')
	{
		ft_nuke_first_mem(vars);
		free(t);
		ft_printf("shitty map\n");
		exit(0);
	}
	else
		return ;
}

void	ft_check_exit(t_vars *vars)
{
	if (vars->num_c == 0)
	{
		ft_printf("BRAVOOO!!!\n");
		nuke_mem(vars);
	}
}

int	check_elm(t_vars *vars)
{
	int	y;
	int	x;

	x = 0;
	y = vars->win_h - 1;
	while (y >= 0)
	{
		while (vars->map[y][x] != '\0' && vars->map[y][x] != '\n')
		{
			if (vars->map[y][x] == 'C')
				vars->num_c++;
			else if (vars->map[y][x] == 'P')
				vars->num_p++;
			else if (vars->map[y][x] == 'E')
				vars->num_e++;
			else if (!(vars->map[y][x] == '1' || vars->map[y][x] == '0'))
				ft_nuke_first_mem(vars);
			x++;
		}
		y--;
		x = 0;
	}
	ft_check_num_elm(vars);
	return (1);
}

int	check_border(t_vars *vars)
{
	check_vertical(vars);
	check_orizontal(vars);
	check_vertical_2(vars);
	check_orizontal_2(vars);
	return (1);
}
