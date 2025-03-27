/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:17:10 by dconza            #+#    #+#             */
/*   Updated: 2025/03/10 15:17:11 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;
	int N = 3;

	horde = zombieHorde(N, "Horde");
 	for (int i = 0; i < N; i++)
	{
       std::cout << "Index " << i << ": ";
	   horde[i].announce();
    }

	delete[] horde;
	return (0);
}