/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:19:33 by fmartini          #+#    #+#             */
/*   Updated: 2023/05/31 15:20:03 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<fcntl.h>
#include"get_next_line.h"
#include"so_long.h"


char	**get_map(t_vars *vars, int fd_map)
{
	char	*riga;
	int	r;
	int	i;
	int	new_fd;
	
	r = 0;
	while(riga = get_next_line(fd_map))
		r++;
	vars->map = (char **) malloc((r + 1) * sizeof(char *));
		i = 0;
	close(fd_map);
	new_fd = open("./mappa.ber", O_RDONLY);
	while (i < r)
	{
		riga = get_next_line(fd_map);
		vars->map[i++] = riga;
	}
	vars.map[i] =NULL;
	return(vars.map);
}

/*int	main()
{
	int fd = open("./mappa.ber", O_RDONLY);
	vars.map = get_map(fd);
	int	i;
	
	i = 0;
	while(vars.map[i])
		printf("%s",vars.map[i++]);
}*/
