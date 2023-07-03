/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:19:33 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/29 19:41:22 by fmartini         ###   ########.fr       */
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
