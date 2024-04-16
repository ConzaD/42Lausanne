/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:44:35 by dconza            #+#    #+#             */
/*   Updated: 2024/04/16 09:52:08 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void print_fractal_options(void)
{
	ft_putendl_fd("+===============  Fractales Disponibles  ===============+", 1);
	ft_putendl_fd("Quelle fractale souhaitez-vous visualiser ?", 1);
	ft_putendl_fd("\tM - Mandelbrot", 1);
	ft_putendl_fd("\tJ - Julia", 1);
	ft_putendl_fd("\e[36mExemple d'utilisation :\t./fractol <type>\n\t\t./fractol M\e[0m", 1);
	ft_putstr_fd("\nPour Julia, vous pouvez spécifier les valeurs de départ\n", 1);
	ft_putstr_fd("pour la forme fractale initiale. Les valeurs doivent être comprises\n", 1);
	ft_putendl_fd("entre -2.0 et 2.0 et doivent contenir un point décimal.", 1);
	ft_putendl_fd("\e[36mExemple d'utilisation :\t", 1);
	ft_putendl_fd("./fractol J\n\t\t./fractol J 0.285 0.01\e[0m", 1);
}


void print_color_options(void)
{
	ft_putendl_fd("\n+===============  Affichage des Couleurs  ====================+", 1);
	ft_putendl_fd("Choisissez une couleur d'affichage en fournissant un code hexadécimal.", 1);
	ft_putendl_fd("Le code couleur hexadécimal doit être formaté comme RRGGBB :", 1);
	ft_putendl_fd("\tBlanc :\tFFFFFF\t\tNoir :\t000000", 1);
	ft_putendl_fd("\tRouge :\tFF0000\t\tVert :\t00FF00", 1);
	ft_putendl_fd("\tBleu :\t0000FF\t\tJaune :\tFFFF00", 1);
	ft_putendl_fd("Autres couleurs intéressantes :", 1);
	ft_putendl_fd("\tViolet :\t9933FF\t\tOrange :\tCC6600", 1);
	ft_putendl_fd("\tRose :\tFF3399\t\tTurquoise : 00FF80\t", 1);
	ft_putstr_fd("\e[36mExemple d'utilisation :\t", 1);
	ft_putendl_fd("./fractol <type> <couleur>", 1);
	ft_putendl_fd("\t\t./fractol M 0066FF\e[0m", 1);
	ft_putendl_fd("\nPour Julia, vous ne pouvez spécifier les couleurs qu'après", 1);
	ft_putendl_fd("les valeurs de départ.", 1);
	ft_putstr_fd("\e[36mExemple d'utilisation :\t", 1);
	ft_putendl_fd("./fractol J 0.285 0.01 CC6600\e[0m", 1);
}


void	print_controls(void)
{
	ft_putendl_fd("\n+===============  Controls  =========================+", 1);
	ft_putendl_fd("WASD ou fleches\tbouger la vue ta capté ma gaté.", 1);
	ft_putendl_fd("+/- ou la molette\tzoom mon bro.", 1);
	ft_putendl_fd("barre d'espace\t\tchange les couleurs mama.", 1);
	ft_putendl_fd("click gauche\t\tshift Julia set [Julia seulement].", 1);
	ft_putendl_fd("1, 2, 3, 4, 5\t\tswitch fractals [prank il y en a que 2].", 1);
	ft_putendl_fd("ESC ou fermer la fenetre\tquitter fract'ol.", 1);
	ft_putendl_fd("+====================================================+\n", 1);
}

void	help_msg(t_fractol *f)
{
	ft_putendl_fd("\n+====================================================+", 1);
	ft_putendl_fd("|                     FRACT'OL                       |", 1);
	ft_putendl_fd("+====================================================+\n", 1);
	print_fractal_options();
	print_color_options();
	clean_exit(EXIT_FAILURE, f);
}
