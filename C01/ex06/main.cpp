/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:23:30 by dconza            #+#    #+#             */
/*   Updated: 2025/03/10 15:24:18 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int argc, char **argv)
{
	std::string level;
	Harl harl;

	if (argc != 2)
	{
		std::cout << "Wrong number of arguments!\n";
		return (0);
	}
	level = argv[1];
	harl.complain(level);
	return (0);
}