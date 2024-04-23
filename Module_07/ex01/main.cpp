/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:02:53 by macastan          #+#    #+#             */
/*   Updated: 2024/04/23 11:02:54 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	char	arr01[] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "before: ";
	iter<char>(arr01, 5, printThis<char>);
	iter<char>(arr01, 5, addOne<char>);
	std::cout << std::endl;
	std::cout << "after: ";
	iter<char>(arr01, 5, printThis<char>);
	std::cout << std::endl;

	std::cout << std::endl;
	char	arr02[] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "before: ";
	iter<char>(arr02, 5, printThis<char>);
	iter<char>(arr02, 5, add10<char>);
	std::cout << std::endl;
	std::cout << "after: ";
	iter<char>(arr02, 5, printThis<char>);
	std::cout << std::endl;

	std::cout << std::endl;
	int	arr03[] = {5, 10, 15, 20, 25};
	std::cout << "before: ";
	iter<int>(arr03, 5, printThis<int>);
	iter<int>(arr03, 5, add10<int>);
	std::cout << std::endl;
	std::cout << "after: ";
	iter<int>(arr03, 5, printThis<int>);
	std::cout << std::endl;

	std::cout << std::endl;
	double 	arr04[] = {5.75, 10.55, 15.35, 20.95, 25.45};
	std::cout << "before: ";
	iter<double>(arr04, 5, printThis<double>);
	iter<double>(arr04, 5, addOne<double>);
	std::cout << std::endl;
	std::cout << "after: ";
	iter<double>(arr04, 5, printThis<double>);
	std::cout << std::endl;
	return (0);
}
