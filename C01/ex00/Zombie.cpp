/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:30:00 by dconza            #+#    #+#             */
/*   Updated: 2025/02/14 16:32:06 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(str name)
{
	this->name = name;
	std::cout << "Be careful ! The zombie " << name << " is in the house !" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " died a second time." << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}