/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:43:55 by madamou           #+#    #+#             */
/*   Updated: 2024/07/12 18:45:00 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solver.h"

int	ft_is_valid_line(char **map, int x, int y)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (map[y][i] == x + '0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_valid_collum(char **map, int x, int y)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (map[i][x] == y + '0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_valid_sqare(char **map, int x, int y, int i)
{
	int	_i;
	int	_j;

	_i = 3 * (y / 3);
	_j = 3 * (x / 3);
	y = _i;
	while (y < _i + 3)
	{
		x = _j;
		while (x < _j + 3)
		{
			if (map[y][x] == '0' + i)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_is_valid(char **map, int x, int y, int i)
{
	if (ft_is_valid_line(map, i, y) == 0)
		return (0);
	if (ft_is_valid_collum(map, x, i) == 0)
		return (0);
	if (ft_is_valid_sqare(map, x, y, i) == 0)
		return (0);
	return (1);
}

int	ft_backtrack(char **map, char possibility[9][9][9], int pos)
{
	int	x;
	int	y;
	int	i;

	x = pos % 9;
	y = pos / 9;
	if (pos == 81)
		return (1);
	if (map[y][x] != '0')
		return (ft_backtrack(map, possibility, pos + 1));
	i = 0;
	while (i < (int)ft_strlen(possibility[y][x]))
	{
		if (ft_is_valid(map, x, y, possibility[y][x][i] - '0'))
		{
			map[y][x] = possibility[y][x][i];
			if (ft_backtrack(map, possibility, pos + 1))
				return (1);
		}
		i++;
	}
	map[y][x] = '0';
	return (0);
}
