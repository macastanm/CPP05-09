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
	(void)copy;
}

Span &Span::operator=(const Span &src) {
	if (this != src)
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