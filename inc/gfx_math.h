/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gfx_math.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 14:16:17 by nmartins       #+#    #+#                */
/*   Updated: 2019/06/09 14:14:06 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_MATH_H
# define GFX_MATH_H

# define RANGE_LERP(n,l,u,mi,ma) (((u)-(l))*((x)-(mi))/((ma)-(mi)))+(l)
# define SIGN(n) (n > 0 ? 1 : -1)

int		gfx_math_clamp(int value, int min, int max);
double	gfx_math_lerp(double a, double b, double f);

#endif
