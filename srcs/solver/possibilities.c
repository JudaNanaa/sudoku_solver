/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:45:40 by madamou           #+#    #+#             */
/*   Updated: 2024/07/12 18:46:29 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solver.h"

char	*ft_malloc_pre_possibility(void)
{
	char	*sortie;
	int		i;

	sortie = malloc(sizeof(char) * 10);
	if (!sortie)
		return (NULL);
	i = 0;
	while (i < 9)
	{
		sortie[i] = i + 1 + '0';
		i++;
	}
	sortie[i] = '\0';
	return (sortie);
}

char	*ft_check_line(char **map, int x, int y)
{
	int		i;
	char	*posibilities;

	i = x;
	posibilities = ft_malloc_pre_possibility();
	if (!posibilities)
		return (NULL);
	while (i >= 0)
	{
		if (map[y][i] != '0')
			posibilities[map[y][i] - '0' - 1] = '0';
		i--;
	}
	i = x + 1;
	while (i < 9)
	{
		if (map[y][i] != '0')
			posibilities[map[y][i] - '0' - 1] = '0';
		i++;
	}
	return (posibilities);
}

char	*ft_check_collum(char **map, int x, int y)
{
	int		i;
	char	*posibilities;

	i = y;
	posibilities = ft_malloc_pre_possibility();
	if (!posibilities)
		return (NULL);
	while (i >= 0)
	{
		if (map[i][x] != '0')
			posibilities[map[i][x] - '0' - 1] = '0';
		i--;
	}
	i = y;
	while (i < 9)
	{
		if (map[i][x] != '0')
			posibilities[map[i][x] - '0' - 1] = '0';
		i++;
	}
	return (posibilities);
}

char	*ft_check_sqare(char **map, int x, int y)
{
	int		i;
	int		j;
	char	*posibilities;
	int		cpt_y;
	int		cpt_x;

	i = (x / 3) * 3;
	j = (y / 3) * 3;
	posibilities = ft_malloc_pre_possibility();
	if (!posibilities)
		return (NULL);
	cpt_y = 0;
	while (cpt_y < 3)
	{
		cpt_x = 0;
		while (cpt_x < 3)
		{
			if (map[j + cpt_y][i + cpt_x] != '0')
				posibilities[map[j + cpt_y][i + cpt_x] - '0' - 1] = '0';
			cpt_x++;
		}
		cpt_y++;
	}
	return (posibilities);
}
