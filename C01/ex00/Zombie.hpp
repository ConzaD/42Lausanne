/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:30:20 by dconza            #+#    #+#             */
/*   Updated: 2025/02/14 16:32:24 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

typedef std::string str;

class Zombie
{
	public:
		Zombie(str name);
		~Zombie();

		Zombie* newZombie(str name);
		void	randomChump(str name);
	private:
		void	announce();
		str	name;
};


#endif