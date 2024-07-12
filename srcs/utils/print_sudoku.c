/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:05:59 by madamou           #+#    #+#             */
/*   Updated: 2024/07/12 18:57:11 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solver.h"

void	ft_print_sudoku(char **map)
{
	int	y;
	int	x;

	y = 0;
	printf("- - - - - - - - - - - - -\n");
	while (map[y])
	{
		x = 0;
		printf("| ");
		while (map[y][x])
		{
			printf("%c ", map[y][x]);
			x++;
			if (x % 3 == 0)
				printf("| ");
		}
		printf("\n");
		y++;
		if (y % 3 == 0)
			printf("- - - - - - - - - - - - -\n");
	}
}
