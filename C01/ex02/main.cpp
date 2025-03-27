/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dconza <dconza@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:18:35 by dconza            #+#    #+#             */
/*   Updated: 2025/03/10 15:18:36 by dconza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPRT = &string;
	std::string &stringREF = string;

	std::cout << "The memory address of the string variable: "<< &string << std::endl;
	std::cout << "The memory address held by stringPTR: " << stringPRT << std::endl;
	std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "The value of the string variable: " << string << std::endl;
	std::cout << "The value pointed to by stringPTR: "<< *stringPRT << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

	return (0);
}