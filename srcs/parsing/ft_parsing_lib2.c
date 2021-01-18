/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_lib2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:02:57 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/16 14:26:45 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_while_wspace(char **line)
{
	while (**line == 32 || (**line >= 8 && **line <= 14))
		*line += 1;
	return (1);
}

void	ft_exit_parser(int nb_lines, char **scene_lines, int i, t_scene *scene)
{
	while (i < nb_lines)
	{
		free(scene_lines[i]);
		i++;
	}
	free(scene_lines);
	ft_error_free("File error, please check your .rt file...\n", scene);
}

int		ft_parse_line_ret(char *line)
{
	while (*line == 32 || (*line >= 8 && *line <= 14))
		line += 1;
	if (*line != 0)
		return (0);
	return (1);
}
