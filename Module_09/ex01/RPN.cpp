/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:18:54 by macastan          #+#    #+#             */
/*   Updated: 2024/05/17 15:18:55 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : input(0) {}

RPN::RPN(const RPN &copy) : numbers(copy.numbers) {}

RPN	&RPN::operator=(const RPN &src) {
	if (this != &src)
	{
		if (numbers.empty() == true)
		{
			while (numbers.size() > 0)
			{
				numbers.pop();
			}
		}
		numbers = src.numbers;
	}
	return (*this);
}

RPN::~RPN(){}

RPN::RPN(std::string _input) : input(_input) {}

float	RPN::doStack() {
	float	result;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == ' ')
			continue;
		if (isdigit(input[i]))
		{
			std::string n(1, input[i]);
			numbers.push(std::atof(n.c_str()));
		}
		else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*')
		{
			try {
				result = doCalculation(input[i]);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
				return (0);
			}
			numbers.push(result);
		}
		else
		{
			std::cout << "Error" << std::endl;
			return (0);
		}
	}
	if (numbers.size() > 1)
	{
		std::cout << "There is not enough operations to do the calculation" << std::endl;
		return (0);
	}
	std::cout << numbers.top() << std::endl;
	return (result);
}

float	RPN::doCalculation(char symbol) {
	if (numbers.size() < 2)
	{
		throw errorNoNumbersEnough();
	}

	float	num1;
	float	num2;
	num2 = numbers.top();
	numbers.pop();
	num1 = numbers.top();
	numbers.pop();

	switch (symbol) {
		case '+':
			return (num1 + num2);
			break;
		case '-':
			return (num1 - num2);
			break;
		case '*':
			return (num1 * num2);
			break;
		case '/':
			return (num1 / num2);
			break;
		default:
			throw errorSymbol();
			break;
	}
	return (0);
}