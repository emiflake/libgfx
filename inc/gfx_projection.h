/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_projection.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/05 13:37:11 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/05 13:38:57 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_PROJECTION_H
# define GFX_PROJECTION_H

# include "gfx_primitive_types.h"

t_vec3 gfx_rotation_x(t_vec3 v, double theta);
t_vec3 gfx_rotation_y(t_vec3 v, double theta);
t_vec3 gfx_rotation_z(t_vec3 v, double theta);

/*
** The same as above, but all at once
*/
t_vec3 gfx_rotation(t_vec3 v, t_vec3 thetas);

#endif
