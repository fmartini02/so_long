/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:26:43 by fmartini          #+#    #+#             */
/*   Updated: 2023/06/27 18:05:02 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **tab, t_point s, t_point b)
{
	if (b.y < 0 || b.x < 0 
		|| b.x >= s.x || b.y >= s.y 
		|| (tab[b.y][b.x] == '1' ))
		return ;
	if (tab[b.y][b.x] == 'E')
	{
		tab[b.y][b.x] = '1';
		return ;
	}
	tab[b.y][b.x] = '1';
	flood_fill(tab, s, (t_point){b.x - 1, b.y});
	flood_fill(tab, s, (t_point){b.x + 1, b.y});
	flood_fill(tab, s, (t_point){b.x, b.y - 1});
	flood_fill(tab, s, (t_point){b.x, b.y + 1});
}
