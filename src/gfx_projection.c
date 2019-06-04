/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_projection.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/05 13:39:28 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/03 19:03:05 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gfx_projection.h"
#include <math.h>

t_vec3		gfx_rotation_x(t_vec3 v, double theta)
{
	t_vec3 after_rot;

	after_rot.x = v.x;
	after_rot.y = cos(theta) * v.y + sin(theta) * v.z;
	after_rot.z = -sin(theta) * v.y + cos(theta) * v.z;
	return (after_rot);
}

t_vec3		gfx_rotation_y(t_vec3 v, double theta)
{
	t_vec3 after_rot;

	after_rot.x = cos(theta) * v.x + sin(theta) * v.z;
	after_rot.y = v.y;
	after_rot.z = -sin(theta) * v.x + cos(theta) * v.z;
	return (after_rot);
}

t_vec3		gfx_rotation_z(t_vec3 v, double theta)
{
	t_vec3 after_rot;

	after_rot.x = cos(theta) * v.x - sin(theta) * v.y;
	after_rot.y = sin(theta) * v.x + cos(theta) * v.y;
	after_rot.z = v.z;
	return (after_rot);
}

t_vec3		gfx_rotation(t_vec3 v, t_vec3 thetas)
{
	return (gfx_rotation_x(gfx_rotation_y(
		gfx_rotation_z(v, thetas.z), thetas.y), thetas.x));
}
