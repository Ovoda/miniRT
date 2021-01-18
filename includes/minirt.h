/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:28:13 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/13 11:47:57 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define TRUE 1
# define FALSE 0
# define SPEC 80

# include "../libs/ft_libc/ft_libc.h"
# include "../libs/minilibx-linux/mlx.h"
# include "ft_objects.h"
# include "ft_parser.h"
# include "ft_render.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

int		ft_render(t_scene scene, t_env *env);
#endif
