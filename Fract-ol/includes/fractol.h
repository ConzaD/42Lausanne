/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:48:47 by dconza            #+#    #+#             */
/*   Updated: 2024/04/17 15:46:47 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "keys.h"
# include <stdio.h>
# include <math.h>

# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 60

# define MANDELBROT 1
# define JULIA 2

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	double	sx;
	double	rx;
	double	fx;
	int		*palette;
	int		color_pattern;
	int		color;
}	t_fractol;



//drawing
int	julia_shift(int x, int y, t_fractol *f);

//schema
int	mandelbrot(double cr, double ci);
int	julia(t_fractol *f, double zr, double zi);

//execution
int	keyboard_exec(int keycode, t_fractol *mlx);
int	mouse_exec(int keycode, int x, int y, t_fractol *mlx);

//color interpolation
void	set_color_multiple(t_fractol *f, int colors[4], int n);
void	set_color_mono(t_fractol *f, int color);

//color
void	color_shift(t_fractol *f);

//exit
void	clean_exit(int exit_code, t_fractol *f);
int	msg(char *str1, char *str2, int err_no);
int	end_fractol(t_fractol *mlx);

//init
void	init(t_fractol *f);
void	reinit_img(t_fractol *f);
void	get_layout(t_fractol *f);
void	clean_init(t_fractol *f);

//msg
void print_fractal_options(void);
void print_color_options(void);
void	print_controls(void);
void	help_msg(t_fractol *f);

//parsing color
void	get_color(t_fractol *f, int ac, char **av);
double	ft_atoif(char *str);

//render
void	render(t_fractol *f);

//striped color
int	get_percent_color(int color, double percent);
void	set_color_zebra(t_fractol *f, int color);
void	set_color_triad(t_fractol *f, int color);
void	set_color_tetra(t_fractol *f, int color);

//more color
void	set_color_opposites(t_fractol *f, int color);
void	set_color_contrasted(t_fractol *f, int color);
void	set_color_graphic(t_fractol *f, int color);
#endif
