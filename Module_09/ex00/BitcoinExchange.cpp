/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:18:00 by macastan          #+#    #+#             */
/*   Updated: 2024/05/17 15:18:02 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : fileName(0) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : fileName(copy.fileName), dataCSV(copy.dataCSV) {}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src) {
	if (this != &src)
	{
		fileName = src.fileName;
		dataCSV.clear();
		dataCSV = src.dataCSV;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string _fileName) : fileName(_fileName) {}

void	BitcoinExchange::organizeDataBase() {
	std::ifstream	dataOG;
	std::string		dataLine;
	size_t			i = 0;
	std::string		data;
	std::string		exchangeStr;
	float			exchange;

	dataOG.open("data.csv");
	if (!dataOG.is_open())
	{
		std::cout << "data.csv: ";
		throw errorFileOpen();
	}
	while (std::getline(dataOG, dataLine))
	{
		i = dataLine.find(",");
		data = dataLine.substr(0, i);
		exchangeStr = dataLine.substr(i + 1, dataLine.size());
		exchange = std::atof(exchangeStr.c_str());
		dataCSV[data] = exchange;
	}
	dataCSV.erase("date");
	dataOG.close();
	/*std::map<std::string, float>::iterator it = dataCSV.begin();
	while (it != dataCSV.end())
	{
		std::cout << it->first << " and " << it->second << std::endl;
		it++;
	}
	std::cout << std::endl << fileName << std::endl;*/
}

void	BitcoinExchange::organizeDataFile() {
	std::ifstream	fileOG;
	std::string		fileLine;
	size_t			i = 0;
	std::string		data;
	std::string		exchangeStr;
	float			exchange;

	fileOG.open(fileName);
	if (!fileOG.is_open())
	{
		std::cout << fileName << ": ";
		throw errorFileOpen();
	}
}