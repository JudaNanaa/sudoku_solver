/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:15:36 by madamou           #+#    #+#             */
/*   Updated: 2024/07/12 19:06:15 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solver.h"

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		return (printf("Pas le bon nombre d'arguments\n"), -1);
	map = ft_parse_args(argv[1]);
	if (!map)
		return (-1);
	ft_print_sudoku(map);
	ft_sudoku_solver(map);
	printf("            *     \n");
	printf("            *     \n");
	printf("            *     \n");
	printf("            *     \n");
	printf("       ***********\n");
	printf("        ********* \n");
	printf("         *******  \n");
	printf("          *****   \n");
	printf("           ***    \n");
	printf("            *     \n");
	ft_print_sudoku(map);
	ft_free_split(map);
	return (0);
}
