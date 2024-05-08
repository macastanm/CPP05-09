/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:59:02 by macastan          #+#    #+#             */
/*   Updated: 2024/04/30 15:59:03 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> g1;

	for (int i = 1; i <= 10; i++)
		g1.push_back(i * 10);
	std::cout << "Testing with vector, this is the vector:" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << g1[i] << " ";
	std::cout << std::endl << "Trying to find the value 100:" << std::endl;
	easyfind(g1, 100);
	std::cout << "Trying to find the value 25:" << std::endl;
	easyfind(g1, 25);
	std::cout << std::endl;

	std::list<int> g2;
	g2.push_back(12);
	g2.push_back(45);
	g2.push_back(8);
	g2.push_back(6);
	g2.push_back(77);

	std::cout << "Testing with list, this is the list:" << std::endl;
	std::list<int>::iterator it;
	for (it = g2.begin(); it != g2.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl << "Trying to find the value 8:" << std::endl;
	easyfind(g2, 8);
	std::cout << "Trying to find the value 25:" << std::endl;
	easyfind(g2, 25);
	std::cout << std::endl;

	std::set<int> g3;
	g3.insert(10);
	g3.insert(36);
	g3.insert(12);
	g3.insert(4);

	std::cout << "Testing with set, this is the set:" << std::endl;
	std::set<int>::iterator itr;
	for (itr = g3.begin(); itr != g3.end(); itr++) {
		std::cout << *itr << " ";
	}
	std::cout << std::endl << "Trying to find the value 4:" << std::endl;
	easyfind(g3, 4);
	std::cout << "Trying to find the value 25:" << std::endl;
	easyfind(g3, 25);
	return (0);
}