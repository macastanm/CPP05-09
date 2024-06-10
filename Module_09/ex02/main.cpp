/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:19:26 by macastan          #+#    #+#             */
/*   Updated: 2024/05/17 15:19:28 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	checkDuplicate(int arc, char **arv)
{
	int j = 0;
	for (int i = 1; i < arc; i++)
	{
		j = i + 1;
		while (j < arc)
		{
			if (std::atoi(arv[i]) == std::atoi(arv[j]))
				return (1);
			j++;
		}
	}
	return (0);
}

int	checkDigit(std::string	valueToCheck)
{
	for (size_t j = 0; j < valueToCheck.size(); j++)
	{
		if (!isdigit(valueToCheck[j]))
		{
			if (valueToCheck[j] == '-')
				continue;
			else
				return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "The program needs arguments" << std::endl;
		return (0);
	}
	if (argc == 2 && checkDigit(argv[1]) == 0)
	{
		std::cout << "Not enough numbers to sort" << std::endl;
		return (0);
	}
	if (argc == 2 && checkDigit(argv[1]) == 1)
	{
		std::cout << "Please insert numbers, more than one" << std::endl;
		return (0);
	}
	for (int j = 1; j < argc; j++)
	{
		if (checkDigit(argv[j]) == 1)
		{
			std::cout << "Please insert numbers" << std::endl;
			return (0);
		}
	}
	if (checkDuplicate(argc, argv) == 1)
	{
		std::cout << "The program doesn't accept duplicate numbers" << std::endl;
		return (0);
	}
	PmergeMe	arrayToSort(argc, argv);
	arrayToSort.doMergeAndPrintResult();
	return (0);
}
