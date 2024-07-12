/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibilities2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:47:39 by madamou           #+#    #+#             */
/*   Updated: 2024/07/12 18:48:23 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solver.h"

char	*ft_str_fusion(char *dest, char *src)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (dest[i] == '0' || src[i] == '0')
			dest[i] = '0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_fill_for_all(char *posibility, char *line, char *collum, char *sqare)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_str_fusion(line, collum);
	ft_str_fusion(line, sqare);
	while (line[i])
	{
		if (line[i] != '0')
			posibility[j++] = line[i];
		i++;
	}
	posibility[j] = '\0';
	return (0);
}

int	ft_fill(char **map, char possibility[9][9][9], int y, int x)
{
	char	*line;
	char	*collum;
	char	*sqare;

	if (map[y][x] != '0')
	{
		possibility[y][x][0] = map[y][x];
		possibility[y][x][1] = '\0';
	}
	else
	{
		line = ft_check_line(map, x, y);
		if (!line)
			return (-1);
		collum = ft_check_collum(map, x, y);
		if (!collum)
			return (free(line), -1);
		sqare = ft_check_sqare(map, x, y);
		if (!sqare)
			return (free(line), free(collum), -1);
		ft_fill_for_all(possibility[y][x], line, collum, sqare);
		(free(line), free(collum), free(sqare));
	}
	return (0);
}

void	ft_fill_possibility(char **map, char possibility[9][9][9])
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_fill(map, possibility, y, x);
			x++;
		}
		y++;
	}
}
