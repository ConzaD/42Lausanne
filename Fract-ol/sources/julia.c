/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:42:10 by dconza            #+#    #+#             */
/*   Updated: 2024/04/16 10:32:31 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia_shift(int x, int y, t_fractol *f)
{
	f->kr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	f->ki = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
	render(f);
	return (0);
}

int	julia(t_fractol *f, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->ki;
		zr = zr * zr - zi * zi + f->kr;
		zi = tmp;
		n++;
	}
	return (n);
}
