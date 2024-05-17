/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:02:31 by macastan          #+#    #+#             */
/*   Updated: 2024/04/30 16:02:32 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : size(0) {}

Span::Span(const Span &copy) : spanContainer(copy.spanContainer), size(copy.size) {
}

Span &Span::operator=(const Span &src) {
	if (this != &src)
	{
		size = src.size;
		spanContainer.clear();
		spanContainer = src.spanContainer;
	}
	return(*this);
}

Span::~Span() {}

Span::Span(unsigned int _size) : size(_size) {}

void	Span::addNumber(int number) {
	if (spanContainer.size() >= size)
		throw fullContainer();
	spanContainer.push_back(number);
}

int Span::longestSpan() {
	if (spanContainer.size() <= 1)
		throw noSpan();
	std::vector<int> spanSorted;
	spanSorted = spanContainer;
	std::sort(spanSorted.begin(), spanSorted.end());
	int i = spanContainer.size();
	return (std::abs((spanSorted[0] - spanSorted[i - 1])));
}

int	Span::shortestSpan() {
	if (spanContainer.size() <= 1)
		throw noSpan();
	int i = spanContainer.size();
	int shortest = std::numeric_limits<int>::max();
	int	check = 0;
	for (int j = 0; j < i; j++)
	{
		for (int k = 1; k < i; k++)
		{
			if (spanContainer[j] == spanContainer[k])
			{
				check++;
				continue ;
			}
			if (std::abs((spanContainer[j] - spanContainer[k])) < shortest)
			{
				shortest = std::abs((spanContainer[j] - spanContainer[k]));
			}
		}
	}
	if (check == ((i - 1) * i))
	{
		return (0);
	}
	return (shortest);
}

void	Span::addManyNumbers(std::vector<int> numbers) {
	if ((spanContainer.size() + numbers.size()) > size)
		throw noSpaceInTheContainer();
	spanContainer.insert(spanContainer.end(), numbers.begin(), numbers.end());
}

void	Span::printVector() {
	std::cout << std::endl << "This is the vector: " << std::endl;
	std::vector<int>::iterator it;
	for (it = spanContainer.begin(); it != spanContainer.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::vector<int> spanSorted;
	spanSorted = spanContainer;
	std::sort(spanSorted.begin(), spanSorted.end());
	std::cout << std::endl << "This is the vector in order: " << std::endl;
	std::vector<int>::iterator it2;
	for (it2 =  spanSorted.begin(); it2 !=  spanSorted.end(); ++it2)
		std::cout << *it2 << " ";
	std::cout << std::endl << std::endl;
}