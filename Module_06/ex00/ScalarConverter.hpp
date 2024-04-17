/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:26:59 by macastan          #+#    #+#             */
/*   Updated: 2024/04/16 11:27:01 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <ctype.h>
# include <limits>
# include <stdlib.h>

class	ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter &operator=(const ScalarConverter& src);
	~ScalarConverter();

public:
	static void	convert(std::string parameter);

	static bool checkChar(std::string parameter);
	static void	printChar(std::string parameter);
	static bool checkInt(std::string parameter);
	static void	printInt(std::string parameter);
	static bool checkFloat(std::string parameter);
	static void	printFloat(std::string parameter);
	static bool checkDouble(std::string parameter);
	static void	printDouble(std::string parameter);
	static bool checkSpecial(std::string parameter);
	static void	printSpecial(std::string parameter);
};

#endif