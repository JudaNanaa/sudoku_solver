/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:19:29 by madamou           #+#    #+#             */
/*   Updated: 2024/07/12 18:57:31 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solver.h"

char	*ft_open_file(char *file)
{
	int		fd;
	char	*line;
	char	*buff;

	buff = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (printf("Error open file\n"), NULL);
	line = get_next_line(fd);
	while (line)
	{
		buff = ft_realloc(buff, ft_strlen(line));
		if (!buff)
			return (printf("Error read file \n"), close(fd), free(line), NULL);
		ft_strcat(buff, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (buff);
}

char	**ft_parse_args(char *file)
{
	char	**map;

	file = ft_open_file(file);
	if (!file)
		return (NULL);
	map = ft_split(file, "\n");
	if (!map)
		return (printf("Error split\n"), free(file), NULL);
	free(file);
	return (map);
}
