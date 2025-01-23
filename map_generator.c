/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapp_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:27:42 by fmartini          #+#    #+#             */
/*   Updated: 2025/01/22 17:52:03 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	get_map(t_vars *vars, int fd_map)
{
	char	*t;
	char	*s;

	s = ft_calloc(1, 1);
	while (1)
	{
		t = get_next_line(fd_map);
		if (t == NULL)
		{
			close(fd_map);
			break ;
		}
		s = ft_strjoin_free(s, t);
		free(t);
	}
	if (!(ft_check_nwline(s)))
		ft_free_init(vars, s);
	vars->map = ft_split(s, '\n');
	vars->temp = ft_split(s, '\n');
	if(vars->map == NULL || vars->temp == NULL)
		ft_free_init(vars, s);
	free(s);
	ft_check_file_map(vars);
}
