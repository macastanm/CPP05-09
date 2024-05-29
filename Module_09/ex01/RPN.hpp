/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:18:58 by macastan          #+#    #+#             */
/*   Updated: 2024/05/17 15:19:00 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <iterator>
# include <fstream>
# include <string>
# include <cstdlib>

class	RPN
{
private:
	std::string	input;
	std::stack<float>	numbers;
public:
	RPN();
	RPN(const RPN& copy);
	RPN	&operator=(const RPN& src);
	~RPN();

	RPN(std::string _input);
	float	doStack();
	float	doCalculation(char symbol);
	class errorNoNumbersEnough : public std::exception
	{
	public:
		virtual const char * what() const throw() {return("There is not enough numbers to do the calculation");}
	};
	class errorSymbol : public std::exception
	{
	public:
		virtual const char * what() const throw() {return("Symbol error");}
	};
};

#endif