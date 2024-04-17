/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:26:53 by macastan          #+#    #+#             */
/*   Updated: 2024/04/16 11:26:56 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	(void)src;
	return(*this);
}

ScalarConverter::~ScalarConverter() {}

bool	ScalarConverter::checkChar(std::string parameter)
{
	if (parameter.length() != 1)
	{
		return (false);
	}
	if (parameter[0] >= '0' && parameter[0] <= '9')
	{
		return (false);
	}
	return (true);
}

void	ScalarConverter::printChar(std::string parameter)
{
	if (parameter[0] >= 32 && parameter[0] <= 126)
	{
		std::cout << "char: '" << parameter << "'" << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(parameter[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(parameter[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(parameter[0]) << ".0" << std::endl;
}

void	ScalarConverter::convert(std::string parameter)
{
	if (checkChar(parameter))
	{
		printChar(parameter);
	}
	else
	{
		std::cout << "passou aqui2\n";
	}
}