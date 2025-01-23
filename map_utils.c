/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:19:33 by fmartini          #+#    #+#             */
/*   Updated: 2025/01/22 19:12:05 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"

int	ft_check_nwline(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			c++;
			i++;
		}
		else if (c >= 2)
			return (0);
		else if (s[i] != '\n')
		{
			c = 0;
			i++;
		}
	}
	return (1);
}

int	ft_check_path(char *p, t_vars *vars)
{
	int		fd;
	char	*path;

	path = p;
	if (!(ft_strstr(path, ".ber")))
	{
		ft_printf("Error:\nmap not .ber!\n");
		free(vars);
		exit(0);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("File not found!\n");
		free(vars);
		exit(0);
	}
	return (fd);
}

void	ft_check_num_elm(t_vars *vars)
{
	if (vars->num_c == 0
		|| vars->num_p == 0
		|| vars->num_e == 0
		|| vars->num_p > 1
		|| vars->num_e > 1)
		ft_nuke_first_mem(vars);
}








