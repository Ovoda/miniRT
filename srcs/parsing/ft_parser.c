/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:27:20 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/16 14:14:18 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_has_obj_letter(char *str, char *id)
{
	size_t i;

	i = 0;
	if (ft_strlen(str) < 5 || ft_strlen(id) < 1)
		return (0);
	if (ft_strlen(id) == 1)
	{
		while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
			i++;
		if (str[i] == *id &&
				((str[i + 1] > 8 && str[i + 1] < 14) || str[i + 1] == 32))
			return (1);
		else
			return (0);
	}
	else
	{
		while ((str[i] != id[0] || str[i + 1] != id[1]) && str[i + 1])
			if (str[++i + 1] == '\0')
				return (0);
	}
	return (1);
}

char	**ft_add_line(char **tab, int nb_of_lines, char *line)
{
	char	**new_tab;
	int		i;

	i = 0;
	if (!(new_tab = (char **)malloc(sizeof(char *) * nb_of_lines + 1)))
		return (0);
	while (i < nb_of_lines - 1)
	{
		new_tab[i] = ft_strdup(tab[i]);
		free(tab[i]);
		i++;
	}
	new_tab[i] = ft_strdup(line);
	free(tab);
	return (new_tab);
}

int		ft_count_obj(char *line, t_nb_obj *nb_of)
{
	if (!ft_has_obj_letter(line, "sp") && !ft_has_obj_letter(line, "pl") &&
			!ft_has_obj_letter(line, "cy") && !ft_has_obj_letter(line, "sq") &&
			!ft_has_obj_letter(line, "tr") && !ft_has_obj_letter(line, "c") &&
			!ft_has_obj_letter(line, "l"))
		return (0);
	else if (ft_has_obj_letter(line, "sp"))
		nb_of->spheres += 1;
	else if (ft_has_obj_letter(line, "pl"))
		nb_of->planes += 1;
	else if (ft_has_obj_letter(line, "c"))
		nb_of->cameras += 1;
	else if (ft_has_obj_letter(line, "cy"))
		nb_of->cylinders += 1;
	else if (ft_has_obj_letter(line, "tr"))
		nb_of->triangles += 1;
	else if (ft_has_obj_letter(line, "sq"))
		nb_of->squares += 1;
	else if (ft_has_obj_letter(line, "l"))
		nb_of->lights += 1;
	return (1);
}

char	**ft_get_lines(int fd, t_nb_obj *nb_obj, int *nb_lines)
{
	int		ret;
	char	*line;
	char	**tab;
	int		nb_of_lines;

	tab = NULL;
	line = NULL;
	(void)nb_lines;
	nb_of_lines = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		nb_of_lines += 1;
		*nb_lines += 1;
		tab = ft_add_line(tab, nb_of_lines, line);
		ft_count_obj(line, nb_obj);
		free(line);
	}
	nb_of_lines += 1;
	*nb_lines += 1;
	tab = ft_add_line(tab, nb_of_lines, line);
	ft_count_obj(line, nb_obj);
	free(line);
	return (tab);
}

int		ft_parser(char *file, t_scene *scene)
{
	int			fd;
	char		**scene_lines;
	int			i;
	int			file_index;
	int			nb_lines;

	i = -1;
	nb_lines = 0;
	file_index = ft_strlen(file);
	if (file[file_index - 1] != 't' ||
			file[file_index - 2] != 'r' || file[file_index - 3] != '.')
		ft_error("File needs .rt extension...\n");
	if ((fd = open(file, O_RDONLY)) <= 0)
		ft_error("Couldn't open file...\n");
	scene_lines = ft_get_lines(fd, &scene->nb_of, &nb_lines);
	ft_init_scene_list(scene);
	while (++i < nb_lines)
	{
		if (!ft_parse_line(scene_lines[i], scene) ||
			!ft_check_only_letter(scene_lines[i]))
			ft_exit_parser(nb_lines, scene_lines, i, scene);
		free(scene_lines[i]);
	}
	free(scene_lines);
	return (0);
}
