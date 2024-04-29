/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:03:48 by macastan          #+#    #+#             */
/*   Updated: 2024/04/23 11:03:50 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdio.h>
# include <stdlib.h>

template <typename T>
class Array
{
private:
	T	*array;
	unsigned int	arraySize;
public:
	Array() : arraySize(0) {
		array = new T[arraySize];
	}
	Array(unsigned int size) : arraySize(size) {
		array = new T[arraySize];
		for (unsigned int i = 0; i < size; i++)
		{
			array[i] = T();
		}
	}
	Array(const Array& copy) : arraySize(copy.arraySize) {
		array = new T[copy.arraySize];
		for (unsigned int i = 0; i < arraySize; i++)
		{
			array[i] = T();
		}
	}
	Array &operator=(const Array& src) {
		if (this != src)
		{
			delete [] array;
			arraySize = src.arraySize;
			array = new T[src.arraySize];
			for (unsigned int i = 0; i < arraySize; i++)
			{
				array[i] = T();
			}
		}
		return (*this);
	}
	~Array() {
		if (array)
		{
			delete [] array;
		}
	}
	class outOfBounds : public std::exception
	{
	public:
		virtual const char * what() const throw() {return("index is out of bounds");}
	};
	T &operator[](unsigned int n) const {
		if (n >= arraySize)
		{
			throw outOfBounds();
		}
		return (array[n]);
	}
	unsigned int	size(void) {
		return (arraySize);
	}
};

#endif
