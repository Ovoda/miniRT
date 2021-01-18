/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:40:23 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/13 11:18:27 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDER_H
# define FT_RENDER_H

# include "minirt.h"

int				adjust_int(int color);
int				ft_display(t_env *env, int nb_cams, t_scene *scene);
int				ft_get_delta(t_vect d, t_ray ray, t_obj obj);
int				ft_coef_x_color(t_color_coef rgb, int color);
int				ft_save(int argc, char **argv, t_scene *scene, t_env *env);
void			ft_init_world(t_scene *scene);
void			ft_render_pixel(t_scene scene, t_img *img,
				t_ray ray, int index);
void			ft_get_normal(t_ray ray, t_vect obj_pos,
				t_inter_point *inter_point);
void			ft_add_coef(t_color_coef *rgb, double ratio, int color,
				t_phong phong);
double			get_norm(t_vect vect);
double			dot(t_vect a, t_vect b);
double			ft_max(double a, double b);
double			ft_min(double a, double b);
t_vect			normalize(t_vect a);
t_vect			sub(t_vect a, t_vect b);
t_vect			add(t_vect a, t_vect b);
t_vect			cross(t_vect a, t_vect b);
t_vect			ft_scale(t_vect a, double b);
t_vect			multiply(t_vect a, t_vect b);
t_vect			ft_get_atob_len(t_vect a, t_vect b);
t_vect			vector(double x, double y, double z);
t_phong			ft_lightning(t_ray ray, t_inter_point inter_point,
				t_vect light_pos);
t_matrix		ft_look_at(t_vect cam_dir);
t_color_coef	ft_coef_p_coef(t_color_coef a, t_color_coef b);
t_inter_point	ft_objs_inter(t_scene scene, t_ray ray, int current_id);
t_inter_point	ft_cylinder_collision(t_ray ray, t_pack cylinder, int id);
t_inter_point	ft_plane_collision(t_ray ray, t_vect point, t_vect normal);
t_inter_point	ft_triangle_collision(t_ray ray, t_vect a, t_vect b, t_vect c);
t_inter_point	ft_square_collision(t_ray ray, t_vect pos, t_vect rot,
				double height);
t_inter_point	ft_sphere_collision(t_ray ray, t_vect pos, double diameter,
				int id);
t_inter_point	ft_get_min(t_inter_point min, t_inter_point current,
				t_obj_list lst, int index);

#endif
