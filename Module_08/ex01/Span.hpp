/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:02:26 by macastan          #+#    #+#             */
/*   Updated: 2024/04/30 16:02:28 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <iterator>
# include <list>
# include <set>

class	Span
{
private:
	std::vector<int> spanContainer;
	unsigned int	size;

public:
	Span();
	Span(const Span& copy);
	Span &operator=(const Span& src);
	~Span();
	Span(unsigned int _size);

	void	addNumber(int number);
	class fullContainer : public std::exception
	{
	public:
		virtual const char * what() const throw() {return("The container is already full");}
	};
	int		shortestSpan(void);
	int		longestSpan(void);
	class noSpan : public std::exception
	{
	public:
		virtual const char * what() const throw() {return("No span can be found");}
	};
};

#endif