/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:19:12 by madamou           #+#    #+#             */
/*   Updated: 2024/07/12 19:01:55 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solver.h"

void	ft_set_backtrack(char **map, char tab_rep[10][10],
		char possibility[9][9][9])
{
	int	i;
	int	x;

	i = 0;
	while (i < 9)
	{
		ft_memset(tab_rep[i], '0', 9);
		tab_rep[i++][9] = '\0';
	}
	i = 0;
	while (map[i])
	{
		x = 0;
		while (map[i][x])
		{
			map[i][x] = possibility[i][x][0];
			x++;
		}
		i++;
	}
}

void	ft_sudoku_solver(char **map)
{
	char	possibility[9][9][9];
	int		y;
	int		x;
	int		cpt;

	cpt = 1;
	while (cpt != 0)
	{
		cpt = 0;
		ft_fill_possibility(map, possibility);
		y = -1;
		while (++y < 9)
		{
			x = -1;
			while (++x < 9)
			{
				if (ft_strlen(possibility[y][x]) == 1 && map[y][x] == '0')
				{
					map[y][x] = possibility[y][x][0];
					cpt++;
				}
			}
		}
	}
	ft_backtrack(map, possibility, 0);
}
