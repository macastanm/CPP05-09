/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:19:46 by macastan          #+#    #+#             */
/*   Updated: 2024/05/17 15:19:48 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) : arrayVec(copy.arrayVec), arrayDeq(copy.arrayDeq) {}

PmergeMe	&PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src)
	{
		arrayVec.clear();
		arrayVec = src.arrayVec;
		arrayDeq.clear();
		arrayDeq = src.arrayDeq;
	}
	return (*this);
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(int arc, char **arv) {
	for (int i = 1; i < arc; i++)
	{
		arrayVec.push_back(std::atoi(arv[i]));
		arrayDeq.push_back(std::atoi(arv[i]));
	}
}

void	PmergeMe::doMergeAndPrintResult() {
	size_t	i = 0;
	std::cout << "Before: ";
	while (i < arrayVec.size())
	{
		std::cout << arrayVec[i] << " ";
		i++;
	}
	std::cout << std::endl;

	clock_t	startVec = clock();
	mergeSortVec(arrayVec);
	clock_t	endVec = clock();

	std::cout << "After: ";
	i = 0;
	while (i < arrayVec.size())
	{
		std::cout << arrayVec[i] << " ";
		i++;
	}
	std::cout << std::endl;

	double	totalVec;
	totalVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << arrayVec.size() << " elements with std::vector : " << totalVec << std::endl;
}

void	PmergeMe::mergeSortVec(std::vector<int> &array) {
	size_t	length = array.size();
	if (length <= 1)
		return;

	std::vector<int>	leftArray;
	std::vector<int>	rightArray;
	size_t 	middle = length / 2;

	for (size_t i = 0; i < length; i++)
	{
		if (i < middle)
		{
			leftArray.push_back(array[i]);
		}
		else
		{
			rightArray.push_back(array[i]);
		}
	}
	mergeSortVec(leftArray);
	mergeSortVec(rightArray);
	mergeVec(leftArray, rightArray, array);
}

void PmergeMe::mergeVec(std::vector<int> &leftArray, std::vector<int> &rightArray, std::vector<int> &array) {
	size_t	i = 0;
	size_t	l = 0;
	size_t	r = 0;

	while (l < leftArray.size() && r < rightArray.size())
	{
		if (leftArray[l] < rightArray[r])
		{
			array[i] = leftArray[l];
			i++;
			l++;
		}
		else
		{
			array[i] = rightArray[r];
			i++;
			r++;
		}
	}
	while (l < leftArray.size())
	{
		array[i] = leftArray[l];
		i++;
		l++;
	}
	while (r < rightArray.size())
	{
		array[i] = rightArray[r];
		i++;
		r++;
	}
}