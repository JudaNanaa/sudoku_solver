/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:14:39 by madamou           #+#    #+#             */
/*   Updated: 2024/07/12 18:53:38 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "../libft/libft.h"
# include <stdio.h>

// Parsing
char	**ft_parse_args(char *file);

// Utils
void	ft_print_sudoku(char **map);

// Solver
void	ft_sudoku_solver(char **map);
int		ft_backtrack(char **map, char possibility[9][9][9], int pos);
void	ft_fill_possibility(char **map, char possibility[9][9][9]);
char	*ft_check_line(char **map, int x, int y);
char	*ft_check_collum(char **map, int x, int y);
char	*ft_check_sqare(char **map, int x, int y);

#endif