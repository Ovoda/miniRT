/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:32:38 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/16 14:27:27 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "minirt.h"

int		ft_error(char *str);
int		ft_error_free(char *str, t_scene *scene);
int		ft_parse_line_ret(char *line);
int		ft_get_nbr_len(int n);
int		ft_get_rgba(char **line);
int		ft_atoi_error(char **str, int *nb);
int		ft_is_white_space(char c);
int		ft_free_lst(t_list **lst);
int		ft_check_params(t_scene scene);
int		ft_init_scene_list(t_scene *scene);
int		ft_get_pos(char **line, t_obj *obj);
int		ft_get_rot(char **line, t_obj *obj);
int		ft_get_diam(char **line, t_obj *obj);
int		ft_get_height(char **line, t_obj *obj);
int		ft_parser(char *file, t_scene *scene);
int		ft_has_obj_letter(char *line, char *id);
int		ft_get_light(char *line, t_scene *scene);
int		ft_get_camera(char *line, t_scene *scene);
int		ft_parse_line(char *line, t_scene *scene);
int		ft_get_resolution(char **line, t_scene *scene);
int		ft_get_vect(char **line, int is_unit, t_vect *a);
int		ft_get_ambient_light(char *line, t_scene *scene);
int		ft_get_triangle(char *line, t_scene *scene, int id);
int		ft_get_obj(char *line, t_scene *scene, int type, int id);
int		ft_isnum(char **line);
int		ft_while_num(char **line);
int		ft_while_wspace(char **line);
int		ft_iscomma_inc(char **line);
int		ft_while_num_or_neg(char **line);
int		ft_isnum_neg(char **line);
int		ft_check_only_letter(char *line);
void	ft_free(t_scene *scene);
void	ft_while_not_num(char **line);
void	ft_while_not_wspace(char **line);
void	ft_init_scene(t_scene *scene);
void	ft_exit_parser(int nb_lines, char **scene_lines,
		int i, t_scene *scene);
double	ft_atof(char *str);
#endif
