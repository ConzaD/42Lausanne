/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:20:41 by dconza            #+#    #+#             */
/*   Updated: 2025/03/10 15:20:48 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string _type;
	public:
		// Constructors
		Weapon();
		Weapon(std::string type);
		~Weapon();

		// Member functions
		void setType(std::string type);
		const std::string &getType() const;
};

#endif