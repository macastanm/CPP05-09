/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:03:12 by macastan          #+#    #+#             */
/*   Updated: 2024/04/23 11:03:13 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T> void iter(T *array, int length, void (*f)(T &))
{
	for (int j = 0; j < length; j++)
	{
		f(array[j]);
	}
}

template <typename T> void add10(T &x)
{
	x += 10;
}

template <typename T> void addOne(T &x)
{
	x += 1;
}

template <typename T> void printThis(T &x)
{
	std::cout << x << " ";
}

#endif
