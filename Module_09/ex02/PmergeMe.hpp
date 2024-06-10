/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:19:52 by macastan          #+#    #+#             */
/*   Updated: 2024/05/17 15:19:54 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <iterator>
# include <fstream>
# include <string>
# include <cstdlib>
# include <time.h>

class	PmergeMe
{
private:
	std::vector<int>	arrayVec;
	std::deque<int>		arrayDeq;

public:
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe	&operator=(const PmergeMe& src);
	~PmergeMe();

	PmergeMe(int arc, char **arv);
	void	doMergeAndPrintResult(void);
	void	mergeSortVec(std::vector<int> &array);
	void	mergeVec(std::vector<int> &leftArray, std::vector<int> &rightArray, std::vector<int> &array);
};

//leftArray = std::vector<int>(array.begin(), array.begin() + middle);
//	rightArray = std::vector<int>(array.begin() + middle, array.end());

#endif