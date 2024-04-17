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

bool	ScalarConverter::checkInt(std::string parameter)
{
	int i = 0;
	if (parameter[i] == '-')
	{
		i++;
	}
	while (parameter[i])
	{
		if (!isdigit(parameter[i]))
		{
			return(false);
		}
		i++;
	}
	long int	m = atol(parameter.c_str());
	if (m > std::numeric_limits<int>::max() || m < std::numeric_limits<int>::min())
	{
		return (false);
	}
	return (true);
}

bool	ScalarConverter::checkFloat(std::string parameter)
{
	if (parameter[parameter.length() - 1] != 'f')
	{
		return (false);
	}
	int i = 0;
	int flag = 0;
	if (parameter[0] == '-')
	{
		i++;
	}
	while (parameter[i + 1])
	{
		if (parameter[i] == '.')
		{
			flag++;
		}
		if (!isdigit(parameter[i]) && parameter[i] != '.')
		{
			return(false);
		}
		i++;
	}
	if (flag != 1)
	{
		return (false);
	}
	double 	m = atof(parameter.c_str());
	if (m > std::numeric_limits<float>::max() || m < -std::numeric_limits<float>::max())
	{
		return (false);
	}
	return (true);
}

bool	ScalarConverter::checkDouble(std::string parameter)
{
	int i = 0;
	int flag = 0;
	if (parameter[0] == '-')
	{
		i++;
	}
	while (parameter[i])
	{
		if (parameter[i] == '.')
		{
			flag++;
		}
		if (!isdigit(parameter[i]) && parameter[i] != '.')
		{
			return(false);
		}
		i++;
	}
	if (flag != 1)
	{
		return (false);
	}
	long double m = strtold( parameter.c_str(), NULL);
	if (m > std::numeric_limits<double>::max() || m < -std::numeric_limits<double>::max())
	{
		return (false);
	}
	return (true);
}

bool	ScalarConverter::checkSpecial(std::string parameter)
{
	if(parameter == "-inff" || parameter == "+inff" || parameter == "nanf" || parameter == "-inf" || parameter == "+inf" || parameter == "nan")
	{
		return(true);
	}
	return(false);
}

void	ScalarConverter::printChar(std::string parameter)
{
	if (parameter[0] >= 32 && parameter[0] <= 126)
	{
		std::cout << "char: '" << parameter << "'" << std::endl;
	}
	else
	{
		std::cout << "char: " << "Non displayable" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(parameter[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(parameter[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(parameter[0]) << ".0" << std::endl;
}

void	ScalarConverter::printInt(std::string parameter)
{
	int	parameterInt = atoi(parameter.c_str());
	if (parameterInt >= 32 && parameterInt <= 126)
	{
		std::cout << "char: '" << static_cast<char >(parameterInt) << "'" << std::endl;
	}
	else if (parameterInt < 0 || parameterInt > 127)
	{
		std::cout << "char: " << "Out of range" << std::endl;
	}
	else
	{
		std::cout << "char: " << "Non displayable" << std::endl;
	}
	std::cout << "int: " << parameterInt << std::endl;
	std::cout << "float: " << static_cast<float>(parameterInt) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(parameterInt) << ".0" << std::endl;
}

void	ScalarConverter::printFloat(std::string parameter)
{
	float	parameterFloat = atof(parameter.c_str());
	if (parameterFloat >= 32.0f && parameterFloat <= 126.0f)
	{
		std::cout << "char: '" << static_cast<char >(parameterFloat) << "'" << std::endl;
	}
	else if (parameterFloat < 0.0f || parameterFloat > 127.0f)
	{
		std::cout << "char: " << "Out of range" << std::endl;
	}
	else
	{
		std::cout << "char: " << "Non displayable" << std::endl;
	}
	if (parameterFloat > std::numeric_limits<int>::max() || parameterFloat < std::numeric_limits<int>::min())
	{
		std::cout << "int: " << "Out of range" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(parameterFloat) << std::endl;
	}
	if (parameterFloat - (int)parameterFloat == 0)
	{
		std::cout << "float: " << parameterFloat << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(parameterFloat) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << parameterFloat << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(parameterFloat) << std::endl;
	}
}

void	ScalarConverter::printDouble(std::string parameter)
{
	double	parameterDouble = atof(parameter.c_str());
	if (parameterDouble >= 32.0 && parameterDouble <= 126.0)
	{
		std::cout << "char: '" << static_cast<char >(parameterDouble) << "'" << std::endl;
	}
	else if (parameterDouble < 0.0 || parameterDouble > 127.0)
	{
		std::cout << "char: " << "Out of range" << std::endl;
	}
	else
	{
		std::cout << "char: " << "Non displayable" << std::endl;
	}
	if (parameterDouble > std::numeric_limits<int>::max() || parameterDouble < std::numeric_limits<int>::min())
	{
		std::cout << "int: " << "Out of range" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(parameterDouble) << std::endl;
	}
	if (parameterDouble - (int)parameterDouble == 0)
	{
		if (parameterDouble > std::numeric_limits<float>::max() || parameterDouble < -std::numeric_limits<float>::max())
		{
			std::cout << "float: " << "Out of range" << std::endl;
		}
		else
		{
			std::cout << "float: " << static_cast<float>(parameterDouble) << ".0f" << std::endl;

		}
		std::cout << "double: " << parameterDouble << ".0" << std::endl;
	}
	else
	{
		if (parameterDouble > std::numeric_limits<float>::max() || parameterDouble < -std::numeric_limits<float>::max())
		{
			std::cout << "float: " << "Out of range" << std::endl;
		}
		else
		{
			std::cout << "float: " << static_cast<float>(parameterDouble) << "f" << std::endl;
		}
		std::cout << "double: " << parameterDouble << std::endl;
	}
}

void	ScalarConverter::printSpecial(std::string parameter)
{
	std::cout << "char: " << "Impossible" << std::endl;
	std::cout << "int: " << "Impossible" << std::endl;
	if (parameter == "-inff" || parameter == "+inff" || parameter == "nanf")
	{
		std::cout << "float: " << parameter << std::endl;
	}
	else
	{
		std::cout << "float: " << parameter << "f" << std::endl;
	}
	if (parameter == "-inf" || parameter == "+inf" || parameter == "nan")
	{
		std::cout << "double: " << parameter << std::endl;
	}
	else
	{
		parameter.erase(parameter.end() - 1);
		std::cout << "double: " << parameter << std::endl;
	}
}

void	ScalarConverter::convert(std::string parameter)
{
	if (checkChar(parameter))
	{
		printChar(parameter);
	}
	else if (checkInt(parameter))
	{
		printInt(parameter);
	}
	else if (checkFloat(parameter))
	{
		printFloat(parameter);
	}
	else if (checkDouble(parameter))
	{
		printDouble(parameter);
	}
	else if (checkSpecial(parameter))
	{
		printSpecial(parameter);
	}
	else
		std::cout << "Invalid type" << std::endl;
}