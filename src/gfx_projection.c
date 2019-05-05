/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_projection.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/05 13:39:28 by nmartins       #+#    #+#                */
/*   Updated: 2019/05/05 13:48:46 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_projection.h"
#include <math.h>

t_vec3	gfx_rotation_x(t_vec3 v, double theta)
{
	t_vec3 after_rot;

	after_rot.x = v.x;
	after_rot.y = cos(theta) * v.y + sin(theta) * v.z;
	after_rot.z = -sin(theta) * v.y + cos(theta) * v.z;
	return (after_rot);
}
