/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:17:31 by dconza            #+#    #+#             */
/*   Updated: 2025/03/10 15:17:37 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombieHorde;

	zombieHorde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombieHorde[i] = Zombie(name);
	}
	return (zombieHorde);
}