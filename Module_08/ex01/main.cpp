/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:02:17 by macastan          #+#    #+#             */
/*   Updated: 2024/04/30 16:02:18 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int	main() {
	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "-------------------------------------------------------" << std::endl;
	Span sp2 = Span(10);
	std::srand(std::time(NULL));
	std::vector<int> manyNumbers;
	for(unsigned int i = 0; i < 8; i++)
		manyNumbers.push_back(rand() / 10000000);
	try
	{
		sp2.addManyNumbers(manyNumbers);
		sp2.addNumber(6);
		sp2.addNumber(70);
		sp2.printVector();
		std::cout << "The shortest: " << sp2.shortestSpan() << std::endl;
		std::cout << "The longest: " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}